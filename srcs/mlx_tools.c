/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_tools.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:27:06 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 15:08:09 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

void	lmlx_putpixel(t_app *e, int x, int y, t_rgba c)
{
	int		i;

	if (!((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT)))
		return ;
	i = (x * 4) + (y * e->mlx.size);
	e->mlx.imgdata[i] = (char)c.b;
	e->mlx.imgdata[i + 1] = (char)c.g;
	e->mlx.imgdata[i + 2] = (char)c.r;
	if (!c.a)
		c.a = 0;
	e->mlx.imgdata[i + 3] = (char)c.a;
}

void	lmlx_clearimg(t_app *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			lmlx_putpixel(e, i, j, (t_rgba){0, 0, 0, 0});
	}
}

void	lmlx_init(t_app *e)
{
	e->mlx.ptr = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.ptr, WIDTH, HEIGHT, "doom");
	e->mlx.imgptr = mlx_new_image(e->mlx.ptr, WIDTH, HEIGHT);
	e->mlx.imgdata = mlx_get_data_addr(e->mlx.imgptr, &e->mlx.bpp, &e->mlx.size,
					&e->mlx.endian);
	mlx_mouse_hide();
	mlx_mouse_move(e->mlx.win, HALF_WIDTH, HALF_HEIGHT);
}

void	lmlx_loop(t_app *e)
{
	mlx_hook(e->mlx.win, 2, 0, keyhook_press, e);
	mlx_hook(e->mlx.win, 3, 0, keyhook_release, e);
	mlx_hook(e->mlx.win, 6, 0, mouse_move, e);
	mlx_loop_hook(e->mlx.ptr, main_loop, e);
	//mlx_do_sync(e->mlx.ptr);
	mlx_loop(e->mlx.ptr);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 15:26:06 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:27:13 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

int		mouse_move(int x, int y, t_app *e)
{
	int tx;
	int ty;

	//ft_putstr("\e[1;1H\e[2J");
	tx = 0;
	ty = 0;
	/*if (x != HALF_WIDTH)
	{
		if (x < HALF_WIDTH)
		{
			tx = (HALF_WIDTH - x);
			e->mouse.x = e->mouse.x - (1 + tx);
			e->player.angle = e->player.angle - ((0.05+ (tx / 100)));
		}
		else
		{
			tx = (x - HALF_WIDTH) ;
			e->mouse.x = e->mouse.x + (1 + tx);
			e->player.angle = e->player.angle + ((0.05 + (tx / 100)));
		}
	}
	if (y != HALF_HEIGHT)
	{
		if (y < HALF_HEIGHT)
		{
			ty = (HALF_HEIGHT - y) / 3;
			e->mouse.y = e->mouse.y - (1 + ty);
		}
		else
		{
			ty = (y - HALF_HEIGHT) / 3;
			e->mouse.y = e->mouse.y + (1 + ty);
		}
	}*/
/*
	if (x != HALF_WIDTH)
	{
		if (x < HALF_WIDTH)
  			e->player.angle -= x * 0.00003f;
		else
  			e->player.angle += x * 0.00003f;
	}
*/

	if (x != HALF_WIDTH)
	{
		if (x < HALF_WIDTH)
		{
			tx = (HALF_WIDTH - x);
		}
		else
		{
			tx = (x - HALF_WIDTH) ;
		}
	}
	//e->player.pcos = e->player.angle;
	//e->player.psin = e->player.angle;

			//e->player.ya    = CLAMP(e->player.ya - y * 0.5f, -5, 5);
	
	if (y != HALF_HEIGHT)
	{
		if (y < HALF_HEIGHT)
		{
		}
		else
		{
		}
	}
	mlx_mouse_move(e->mlx.win, HALF_WIDTH, HALF_HEIGHT);
	if (x > WIDTH || x < 0 || y < 0 || y > HEIGHT)
		return (0);
	return (1);
}

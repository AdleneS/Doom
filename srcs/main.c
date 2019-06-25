/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:11:07 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:45:28 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"
#include <stdio.h>

int		main_loop(t_app *e)
{	
	lmlx_clearimg(e);
	//printf("\e[1;1H\e[2J");
	hook_keys(e);
	int i;

	i = -1;
	t_tri	**ttranslated;
	t_tri	**tprojected;
	t_tri	**trotatedzx;
	t_tri	**trotatedz;
	t_matrix matRotZ;
	t_matrix matRotX;
	int o;
	int p;
	o = -1;
	while (++o < 4)
	{
		p = -1;
		while (++p < 4)
			matRotZ.m[o][p] = 0;
	}
	o = -1;
	while (++o < 4)
	{
		p = -1;
		while (++p < 4)
			matRotX.m[o][p] = 0;
	}
	matRotZ.m[0][0] = cosf(e->test);
	matRotZ.m[0][1] = sinf(e->test);
	matRotZ.m[1][0] = -sinf(e->test);
	matRotZ.m[1][1] = cosf(e->test);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(e->test * 1);
	matRotX.m[1][2] = sinf(e->test * 1);
	matRotX.m[2][1] = -sinf(e->test* 1);
	matRotX.m[2][2] = cosf(e->test * 1);
	matRotX.m[3][3] = 1;


	e->test+=0.01;
	tprojected = malloc(sizeof(t_tri *) * 12);
	trotatedzx = malloc(sizeof(t_tri *) * 12);
	trotatedz = malloc(sizeof(t_tri *) * 12);
	ttranslated = malloc(sizeof(t_tri *) * 12);
	
	while (++i < 12)
	{
		tprojected[i] = malloc(sizeof(t_tri));
		ttranslated[i] = malloc(sizeof(t_tri));
		trotatedzx[i] = malloc(sizeof(t_tri));
		trotatedz[i] = malloc(sizeof(t_tri));
		mulitplymatrix(e->mesh->tri[i].vert[0], &trotatedz[i]->vert[0], &matRotZ);
		mulitplymatrix(e->mesh->tri[i].vert[1], &trotatedz[i]->vert[1], &matRotZ);
		mulitplymatrix(e->mesh->tri[i].vert[2], &trotatedz[i]->vert[2], &matRotZ);
		//mulitplymatrix(e->mesh->tri[i].vert[0], &tprojected[i]->vert[0], e->matrix);
		//mulitplymatrix(e->mesh->tri[i].vert[1], &tprojected[i]->vert[1], e->matrix);
		//mulitplymatrix(e->mesh->tri[i].vert[2], &tprojected[i]->vert[2], e->matrix);
		//printf("%f\n", tprojected[i]->vert[0]);
		//printf("%f\n",e->mesh->tri[i].vert[0].x);
	
		mulitplymatrix(trotatedz[i]->vert[0], &trotatedzx[i]->vert[0], &matRotX);
		mulitplymatrix(trotatedz[i]->vert[1], &trotatedzx[i]->vert[1], &matRotX);
		mulitplymatrix(trotatedz[i]->vert[2], &trotatedzx[i]->vert[2], &matRotX);

		*ttranslated[i] = *trotatedzx[i];

		//printf("%f\n", trotatedzx[i]->vert[1].y);
		ttranslated[i]->vert[0].z = trotatedzx[i]->vert[0].z + 3.0f;
		ttranslated[i]->vert[1].z = trotatedzx[i]->vert[1].z + 3.0f;
		ttranslated[i]->vert[2].z = trotatedzx[i]->vert[2].z + 3.0f;


		t_vertex normal;
		t_vertex line1;
		t_vertex line2;
		double l;

		line1.x = ttranslated[i]->vert[1].x - ttranslated[i]->vert[0].x;
		line1.y = ttranslated[i]->vert[1].y - ttranslated[i]->vert[0].y;
		line1.z = ttranslated[i]->vert[1].z - ttranslated[i]->vert[0].z;

		line2.x = ttranslated[i]->vert[2].x - ttranslated[i]->vert[0].x;
		line2.y = ttranslated[i]->vert[2].y - ttranslated[i]->vert[0].y;
		line2.z = ttranslated[i]->vert[2].z - ttranslated[i]->vert[0].z;

		normal.x = line1.y * line2.z - line1.z * line2.y;
		normal.y = line1.z * line2.x - line1.x * line2.z;
		normal.z = line1.x * line2.y - line1.y * line2.x;
		l = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
		normal.x /= l;
		normal.y /= l;
		normal.z /= l;

		if (normal.z < 0)
		{
			mulitplymatrix(ttranslated[i]->vert[0], &tprojected[i]->vert[0], e->matrix);
			mulitplymatrix(ttranslated[i]->vert[1], &tprojected[i]->vert[1], e->matrix);
			mulitplymatrix(ttranslated[i]->vert[2], &tprojected[i]->vert[2], e->matrix);
	
			tprojected[i]->vert[0].x += 1;
			tprojected[i]->vert[0].y += 1;
			tprojected[i]->vert[1].x += 1;
			tprojected[i]->vert[1].y += 1;
			tprojected[i]->vert[2].x += 1;
			tprojected[i]->vert[2].y += 1;
	
			tprojected[i]->vert[0].x *= 0.5 * WIDTH;
			tprojected[i]->vert[0].y *= 0.5 * HEIGHT;
			tprojected[i]->vert[1].x *= 0.5 * WIDTH;
			tprojected[i]->vert[1].y *= 0.5 * HEIGHT;
			tprojected[i]->vert[2].x *= 0.5 * WIDTH;
			tprojected[i]->vert[2].y *= 0.5 * HEIGHT;
			//printf("%f  ||  ", tprojected[i]->vert[2].x * 10);
			//printf("%f  ||  ", tprojected[i]->vert[2].y * 10);
			//printf("%f\n", tprojected[i]->vert[2].z * 10);
			drawtriangle(e, tprojected[i]);
		}
	}
	i = -1;
	//patate(e);
	//ft_putstr("player sector: ");
	//ft_putnbr(e->player.sector);
	//ft_putendl(" ");
	//_trace(e, 100,100,200,100, (t_rgba){255, 255, 255 ,0});
	//printf("%f %f %f \n", e->player.pos_x, e->player.pos_y ,e->player.angle);
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
	return (0);
}

void	drawtriangle(t_app *e, t_tri *t)
{
	_trace(e, t->vert[0].x, t->vert[0].y, t->vert[1].x, t->vert[1].y, (t_rgba){255, 255, 255 ,0});
	_trace(e, t->vert[1].x, t->vert[1].y, t->vert[2].x, t->vert[2].y, (t_rgba){255, 255, 255 ,0});
	_trace(e, t->vert[2].x, t->vert[2].y, t->vert[0].x, t->vert[0].y, (t_rgba){255, 255, 255 ,0});
	//printf("%f  ||  ", t->vert[0].x);
	//printf("%f  ||  ", t->vert[0].y);
	//printf("%f\n", t->vert[0].z);
}

void	main_init(t_app *e)
{
	e->mesh = malloc(sizeof(t_mesh));
	e->matrix = malloc(sizeof(t_matrix));
	e->key.up = 0;
	e->key.down = 0;
	e->key.left = 0;
	e->key.right = 0;
	e->key.jump = 0;
	e->mouse.y = 0;
	e->mouse.x = 0;

	e->sector = (struct sector **)malloc(sizeof(struct sector*) * 3);
}

static void	load_texture_from_file(t_app *e, int i, char *file)
{
	int			w;
	int			h;
	//struct stat	st;

	//if (stat(file, &st) < 0)
	//{
	//	ft_putstr(file);
	//	ft_putstr(" : ");
	//	exitandfree(e, "file not found", 2);
	//}
	w = 64;
	h = 64;
	e->tex[i]->img = mlx_xpm_file_to_image(e->mlx.ptr, file, &w, &h);
	e->tex[i]->imgdata = mlx_get_data_addr(e->tex[i]->img,
				&e->tex[i]->bpp, &e->tex[i]->size, &e->tex[i]->endian);
}

void		load_textures(t_app *e)
{
	int		i;
	int		nbtex;

	nbtex = 2;
	//e->sp = (t_mlx **)malloc(sizeof(t_mlx *) * 2);
	i = -1;
	while (++i < nbtex)
		e->tex[i] = malloc(sizeof(t_mlx));
	load_texture_from_file(e, 0, "/Users/asaba/ProjectClean/DebugDoom/barrel.xpm");
}


int		main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_app		*e;
	
	e = (t_app *)malloc(sizeof(t_app));
	e->test = 0;
	main_init(e);
	createcube(e);
	fmatrix(e);
	lmlx_init(e);
	//printf("%f\n", e->matrix->m[3][2]);
	//load_textures(e);
	lmlx_loop(e);
	return (0);
}

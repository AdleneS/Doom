/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:11:07 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 22:02:49 by asaba       ###    #+. /#+    ###.fr     */
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
	t_tri	**t_projected;
	t_tri	**t_transformed;
	t_tri	**t_viewed;
	
	t_projected = malloc(sizeof(t_tri *) * 12);
	t_transformed = malloc(sizeof(t_tri *) * 12);
	t_viewed = malloc(sizeof(t_tri *) * 12);
	initMatrix_X(e);
	initMatrix_Y(e);
	initMatrix_Z(e);

	//printf("X: %f  ||  ", e->matRotX.m[1][1]);
	//printf("Y: %f  ||  ", e->matRotY.m[1][1]);
	//printf("Z: %f\n", e->matRotZ.m[1][1]);
	//e->test += 0.005;
	e->m_trans = matrix_translation(0.0, 0.0, 2.0);
	matrix_identity(&e->m_world);
	e->m_world = matrix_mulMatrix(e->matRotZ, e->matRotX);
	e->m_world = matrix_mulMatrix(e->m_world, e->m_trans);
	
	t_vertex vUp;
	t_vertex vTarget;
	t_matrix matCamera;
	t_matrix matView;
	
	e->vlookdir = (t_vertex){0, 0 , 1, 1};
	vUp = (t_vertex){0, 1, 0, 1};
	vTarget = v_add(e->vcamera, e->vlookdir);
	matCamera = m_pointAt(e->vcamera, vTarget, vUp);
	matView = m_quickInverse(matCamera);
	while (++i < 12)
	{
		t_projected[i] = malloc(sizeof(t_tri));
		t_transformed[i] = malloc(sizeof(t_tri));
		t_viewed[i] = malloc(sizeof(t_tri));

		t_transformed[i]->vert[0] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[0]);
		t_transformed[i]->vert[1] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[1]);
		t_transformed[i]->vert[2] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[2]);

		t_vertex normal;
		t_vertex line1;
		t_vertex line2;
		double l;

		line1 = v_sub(t_transformed[i]->vert[1], t_transformed[i]->vert[0]);
		line2 = v_sub(t_transformed[i]->vert[2], t_transformed[i]->vert[0]);
		normal = v_crossprod(line1, line2);
		normal = v_normalize(normal);
		l = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
		normal.x /= l;
		normal.y /= l;
		normal.z /= l;
		normal.w = 1;

		e->v_camray = v_sub(t_transformed[i]->vert[0], e->vcamera);

		//if (normal.z < 0)
		if (v_dotproduct(normal, e->v_camray) < 0.0)
		{
			t_viewed[i]->vert[0] = matrix_mulvector(matView, t_transformed[i]->vert[0]);
			t_viewed[i]->vert[1] = matrix_mulvector(matView, t_transformed[i]->vert[1]);
			t_viewed[i]->vert[2] = matrix_mulvector(matView, t_transformed[i]->vert[2]);

			t_projected[i]->vert[0] = matrix_mulvector(e->matProj, t_viewed[i]->vert[0]);
			t_projected[i]->vert[1] = matrix_mulvector(e->matProj, t_viewed[i]->vert[1]);
			t_projected[i]->vert[2] = matrix_mulvector(e->matProj, t_viewed[i]->vert[2]);

			//printf("%f  ||  ", e->matProj.m[0][0]);
			//printf("%f  ||  ", e->matProj.m[1][1]);
			//printf("%f  ||  ", e->matProj.m[2][2]);
			//printf("%f  ||  ", e->matProj.m[3][2]);
			//printf("%f\n\n", e->matProj.m[2][3]);

			t_projected[i]->vert[0] = v_div(t_projected[i]->vert[0], t_projected[i]->vert[0].w);
			t_projected[i]->vert[1] = v_div(t_projected[i]->vert[1], t_projected[i]->vert[1].w);
			t_projected[i]->vert[2] = v_div(t_projected[i]->vert[2], t_projected[i]->vert[2].w);
			
			//printf("%f  ||  ", t_projected[i]->vert[1].x);
			//printf("%f  ||  \n\n", t_projected[i]->vert[2].x);

			t_vertex	v_offsetview;

			v_offsetview = (t_vertex){1.0, 1.0, 0, 1.0};

			t_projected[i]->vert[0] = v_add(t_projected[i]->vert[0], v_offsetview);
			t_projected[i]->vert[1] = v_add(t_projected[i]->vert[1], v_offsetview);
			t_projected[i]->vert[2] = v_add(t_projected[i]->vert[2], v_offsetview);

			t_projected[i]->vert[0].x *= 0.5 * WIDTH;
			t_projected[i]->vert[0].y *= 0.5 * HEIGHT;
			t_projected[i]->vert[1].x *= 0.5 * WIDTH;
			t_projected[i]->vert[1].y *= 0.5 * HEIGHT;
			t_projected[i]->vert[2].x *= 0.5 * WIDTH;
			t_projected[i]->vert[2].y *= 0.5 * HEIGHT;
			drawtriangle(e, t_projected[i]);
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
	e->vcamera = (t_vertex){0, 0, 0, 1};
	e->vlookdir = (t_vertex){0, 0, 0, 1};
	e->v_camray = (t_vertex){0, 0, 0, 1};
	e->sector = (struct sector **)malloc(sizeof(struct sector*) * 3);
	e->fnear = 0.1;
	e->ffar = 1000.0;
	e->ffov = 60.0;
	e->faspectratio = (double)HEIGHT / WIDTH;
	e->ffovrad = 1.0 / tanf(e->ffov * 0.5 / 180 * 3.14159);
	//e->m_world = matrix_identity();
	set_matrix(&e->matRotX);
	set_matrix(&e->matRotY);
	set_matrix(&e->matRotZ);
	set_matrix(&e->m_world);
	init_matrix_proj(e);

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
	lmlx_init(e);
	//load_textures(e);
	lmlx_loop(e);
	return (0);
}

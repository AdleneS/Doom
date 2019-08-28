/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:11:07 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:02:27 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"
#include <stdio.h>

void	pushback(t_sortedtri **list, t_tri tri)
{
	t_sortedtri *tmp;
	t_sortedtri *new;

	new = malloc(sizeof(t_sortedtri));
	new->sortedtri = tri;
	new->next = NULL;

	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next; 
		tmp->next = new;
	}
}

void	swap(t_vertex *a, t_vertex *b)
{
	t_vertex c = *a;
	*a = *b;
	*b = c;
}

int		main_loop(t_app *e)
{	
	lmlx_clearimg(e);
	//printf("\e[1;1H\e[2J");
	hook_keys(e);
	int i;
	int n;

	i = -1;
	n = 0;
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
	
	vUp = (t_vertex){0, 1, 0, 1};
	vTarget = (t_vertex){0, 0, 1 ,1};
	initMatrixCameraRot(e);
	e->vlookdir = matrix_mulvector(e->matRotCamera, vTarget);
	vTarget = v_add(e->vcamera, e->vlookdir);
	matCamera = m_pointAt(e->vcamera, vTarget, vUp);
	matView = m_quickInverse(matCamera);
	e->sortedtri = NULL;
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

			int nclippedtriangles = 0;
			t_tri clipped[2];
			nclippedtriangles = t_clipplane((t_vertex){0.0, 0.0, 0.1, 1.0}, (t_vertex){0.0, 0.0, 1.0, 1.0}, *t_viewed[i], &clipped[0], &clipped[1]);
				
			while (n < nclippedtriangles)
			{
				t_projected[i]->vert[0] = matrix_mulvector(e->matProj, clipped[n].vert[0]);
				t_projected[i]->vert[1] = matrix_mulvector(e->matProj, clipped[n].vert[1]);
				t_projected[i]->vert[2] = matrix_mulvector(e->matProj, clipped[n].vert[2]);
				//t_projected[i]->vert[0] = matrix_mulvector(e->matProj, t_viewed[i]->vert[0]);
				//t_projected[i]->vert[1] = matrix_mulvector(e->matProj, t_viewed[i]->vert[1]);
				//t_projected[i]->vert[2] = matrix_mulvector(e->matProj, t_viewed[i]->vert[2]);

				//printf("1x = %f  ||  ", clipped[1].vert[0].x);
				//printf("1y = %f  ||  ", clipped[1].vert[0].y);
				//printf("1z = %f  ||  \n", clipped[1].vert[0].z);
				//printf("2x = %f  ||  ", clipped[1].vert[1].x);
				//printf("2y = %f  ||  ", clipped[1].vert[1].y);
				//printf("2z = %f  ||  \n", clipped[1].vert[1].z);
				//printf("3x = %f  ||  ", clipped[1].vert[2].x);
				//printf("3y = %f  ||  ", clipped[1].vert[2].y);
				//printf("3z = %f  ||  \n\n\n", clipped[1].vert[2].z);
				
				t_projected[i]->vert[0] = v_div(t_projected[i]->vert[0], t_projected[i]->vert[0].w);
				t_projected[i]->vert[1] = v_div(t_projected[i]->vert[1], t_projected[i]->vert[1].w);
				t_projected[i]->vert[2] = v_div(t_projected[i]->vert[2], t_projected[i]->vert[2].w);

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
				n++;
			}
			pushback(&e->sortedtri, *t_projected[i]);
			//triangle(e, t_projected[i]->vert[0], t_projected[i]->vert[1],t_projected[i]->vert[2], (t_rgba){255,0,0,0});
			//drawtriangle(e, t_projected[i]);
			n = 0;
		}
	}
	drawtriangle(e, e->sortedtri);
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
	void triangle(t_app *e, t_vertex t0, t_vertex t1, t_vertex t2, t_rgba color) 
	{ 
	if (t0.y==t1.y && t0.y==t2.y) return; // I dont care about degenerate triangles 
	// sort the vertices, t0, t1, t2 lower−to−upper (bubblesort yay!) 
	if (t0.y>t1.y) swap(&t0, &t1); 
	if (t0.y>t2.y) swap(&t0, &t2); 
	if (t1.y>t2.y) swap(&t1, &t2); 
	int total_height = t2.y-t0.y; 
	for (int i=0; i<total_height; i++) { 
		int second_half = i>t1.y-t0.y || t1.y==t0.y; 
		int segment_height = second_half ? t2.y-t1.y : t1.y-t0.y; 
		float alpha = (float)i/total_height; 
		float beta  = (float)(i-(second_half ? t1.y-t0.y : 0))/segment_height; // be careful: with above conditions no division by zero here 
		t_vertex A =               v_add(t0, v_mul(v_sub(t2, t0), alpha)); 
		t_vertex B = second_half ? v_add(t1, v_mul(v_sub(t2,t1),beta)) : v_add(t0, v_mul(v_sub(t1,t0),beta)); 
		if (A.x>B.x) swap(&A, &B); 
		for (int j=A.x; j<=B.x; j++) { 
			lmlx_putpixel(e, j, t0.y+i, color); // attention, due to int casts t0.y+i != A.y 
		} 
	} 
}

int		drawtriangle(t_app *e, t_sortedtri *s)
{
	t_sortedtri *tmp = s;
	
	if (!tmp)
		return (0);
	while (tmp)
	{
		_trace(e, tmp->sortedtri.vert[0].x, tmp->sortedtri.vert[0].y, tmp->sortedtri.vert[1].x, tmp->sortedtri.vert[1].y, (t_rgba){255, 255, 255 ,0});
		_trace(e, tmp->sortedtri.vert[1].x, tmp->sortedtri.vert[1].y, tmp->sortedtri.vert[2].x, tmp->sortedtri.vert[2].y, (t_rgba){255, 255, 255 ,0});
		_trace(e, tmp->sortedtri.vert[2].x, tmp->sortedtri.vert[2].y, tmp->sortedtri.vert[0].x, tmp->sortedtri.vert[0].y, (t_rgba){255, 255, 255 ,0});
		tmp = tmp->next;
	}
	return (1);
		//_trace(e, t->vert[0].x, t->vert[0].y, t->vert[1].x, t->vert[1].y, (t_rgba){255, 255, 255 ,0});
		//_trace(e, t->vert[1].x, t->vert[1].y, t->vert[2].x, t->vert[2].y, (t_rgba){255, 255, 255 ,0});
		//_trace(e, t->vert[2].x, t->vert[2].y, t->vert[0].x, t->vert[0].y, (t_rgba){255, 255, 255 ,0});
}

void	main_init(t_app *e)
{
	e->mesh = malloc(sizeof(t_mesh));
	e->matrix = malloc(sizeof(t_matrix));
	//e->sortedtri = malloc(sizeof(t_sortedtri));
	//e->sortedtri = NULL;
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
	e->fYaw = 0;
	//e->m_world = matrix_identity();
	set_matrix(&e->matRotCamera);
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
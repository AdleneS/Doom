/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:11:07 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 15:06:40 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"
#include <stdio.h>

t_rgba	ft_get_pixel(t_mlx img, int x, int y)
{
	t_rgba	rgb;
	int		t;

	if (x < 0 || y < 0 || x >=  384|| y >= 384)
		return ((t_rgba){0, 0, 0, 0});
	t = y * img.size + x * 4;
	rgb.b = img.imgdata[t] + (img.imgdata[t] < 0 ? 256 : 0);
	rgb.g = img.imgdata[t + 1] + (img.imgdata[t + 1] < 0 ? 256 : 0);
	rgb.r = img.imgdata[t + 2] + (img.imgdata[t + 2] < 0 ? 256 : 0);
	rgb.a = img.imgdata[t + 3] + (img.imgdata[t + 3] < 0 ? 256 : 0);
	return (rgb);
}

void	swap(t_vertex *a, t_vertex *b)
{
	t_vertex c = *a;
	*a = *b;
	*b = c;
}
void	swap_int(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void	swap_double(double *a, double *b)
{
	double c = *a;
	*a = *b;
	*b = c;
}

void	textured_triangle(t_app *e, int x1, int y1, double u1, double v1,
		int x2, int y2, double u2, double v2,
		int x3, int y3, double u3, double v3, t_mlx tex)
{
	if (y2 < y1)
	{
		swap_int(&y1, &y2);
		swap_int(&x1, &x2);
		swap_double(&u1, &u2);
		swap_double(&v1, &v2);
	}
	if (y3 < y1)
	{
		swap_int(&y1, &y3);
		swap_int(&x1, &x3);
		swap_double(&u1, &u3);
		swap_double(&v1, &v3);
	}
	if (y3 < y2)
	{
		swap_int(&y2, &y3);
		swap_int(&x2, &x3);
		swap_double(&u2, &u3);
		swap_double(&v2, &v3);
	}

	int		dy1;
	int		dx1;
	int		dy2;
	int		dx2;
	double	dv1;
	double	du1;
	double	dv2;
	double	du2;
	double	dax_step;
	double	dbx_step;
	double	du1_step;
	double	dv1_step;
	double	du2_step;
	double	dv2_step;
	double	tex_u;
	double	tex_v;

	dy1 = y2 - y1;
	dx1 = x2 - x1;
	dv1 = v2 - v1;
	du1 = u2 - u1;
	dy2 = y3 - y1;
	dx2 = x3 - x1;
	dv2 = v3 - v1;
	du2 = u3 - u1;
	dax_step = 0;
	dbx_step = 0;
	du1_step = 0;
	dv1_step = 0;
	du2_step = 0;
	dv2_step = 0;

	if (dy1) dax_step = dx1 / (double)abs(dy1);
	if (dy2) dbx_step = dx2 / (double)abs(dy2);

	if (dy1) du1_step = du1 / (double)abs(dy1);
	if (dy1) dv1_step = dv1 / (double)abs(dy1);

	if (dy2) du2_step = du2 / (double)abs(dy2);
	if (dy2) dv2_step = dv2 / (double)abs(dy2);

	if (dy1)
	{
		int i;
		i = y1;
		while (i <= y2)
		{
			int	ax = x1 + (double)(i - y1) * dax_step;
			int	bx = x1 + (double)(i - y1) * dbx_step;

			double	tex_su = u1 + (double)(i - y1) * du1_step;
			double	tex_sv = v1 + (double)(i - y1) * dv1_step;

			double	tex_eu = u1 + (double)(i - y1) * du2_step;
			double	tex_ev = v1 + (double)(i - y1) * dv2_step;

			if (ax > bx)
			{
				swap_int(&ax, &bx);
				swap_double(&tex_su, &tex_eu);
				swap_double(&tex_sv, &tex_ev);
			}

			tex_u = tex_su;
			tex_v = tex_sv;

			double tstep = 1.0f / ((double)(bx - ax));
			double t = 0.0f;
			int	j = ax;
			while (j < bx)
			{
				tex_u = (1.0f - t) * tex_su + t * tex_eu;
				tex_v = (1.0f - t) * tex_sv + t * tex_ev;
				lmlx_putpixel(e, j, i, ft_get_pixel(*e->tex[0], tex_u * 384.0, tex_v * 384.0 - 1.0f));
				t += tstep;
				j++;
			}
			i++;
		}
	}

		dy1 = y3 - y2;
		dx1 = x3 - x2;
		dv1 = v3 - v2;
		du1 = u3 - u2;

		if (dy1) dax_step = dx1 / (double)abs(dy1);
		if (dy2) dbx_step = dx2 / (double)abs(dy2);

		du1_step = 0.f;
		dv1_step = 0.f;
		if (dy1) du1_step = du1 / (double)abs(dy1);
		if (dy1) dv1_step = dv2 / (double)abs(dy1);
		if (dy1)
		{
			int i = y2;
			while (i <= y3)
			{
				int	ax = x2 + (double)(i - y2) * dax_step;
				int	bx = x1 + (double)(i - y1) * dbx_step;

				double	tex_su = u2 + (double)(i - y2) * du1_step;
				double	tex_sv = v2 + (double)(i - y2) * dv1_step;

				double	tex_eu = u1 + (double)(i - y1) * du2_step;
				double	tex_ev = v1 + (double)(i - y1) * dv2_step;

				if (ax > bx)
				{
					swap_int(&ax, &bx);
					swap_double(&tex_su, &tex_eu);
					swap_double(&tex_sv, &tex_ev);
				}

				tex_u = tex_su;
				tex_v = tex_sv;

				double tstep = 1.0f / ((double)(bx - ax));
				double t = 0.0f;
				int	j = ax;
				while (j < bx)
				{
					tex_u = (1.0f - t) * tex_su + t * tex_eu;
					tex_v = (1.0f - t) * tex_sv + t * tex_ev;
					lmlx_putpixel(e, j, i, ft_get_pixel(*e->tex[0], tex_u * 384.0, tex_v * 384.0 - 1.0f));
					t += tstep;
					j++;
				}
				i++;
			}
		}
}

void	pushback(t_listtri **list, t_tri tri)
{
	t_listtri *tmp;
	t_listtri *new;

	new = malloc(sizeof(t_listtri));
	new->listtri = tri;
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

int		lstsize(t_listtri **list)
{
	t_listtri *tmp;
	int		count;

	count = 0;
	if (!*list)
		return (-1);
	else
	{
		tmp = *list;
		while (tmp->next)
		{
			tmp = tmp->next;
			count++;
		}
	}
	return (count);
}

void	deletefirst(t_listtri *lst)
{
	t_listtri	*todel;
	
	if (!lst)
		return ;
	else
	{
		//todel = lst;
		//lst = lst->next;
		lst = NULL;
		free(lst);

		//todel = NULL;
	}
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
	e->listtri = NULL;
	while (++i < 12)
	{
		t_projected[i] = malloc(sizeof(t_tri));
		t_transformed[i] = malloc(sizeof(t_tri));
		t_viewed[i] = malloc(sizeof(t_tri));

		t_transformed[i]->vert[0] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[0]);
		t_transformed[i]->vert[1] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[1]);
		t_transformed[i]->vert[2] = matrix_mulvector(e->m_world, e->mesh->tri[i].vert[2]);
		t_transformed[i]->t[0] = e->mesh->tri[i].t[0];
		t_transformed[i]->t[1] = e->mesh->tri[i].t[1];
		t_transformed[i]->t[2] = e->mesh->tri[i].t[2];

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
			t_viewed[i]->t[0] = t_transformed[i]->t[0];
			t_viewed[i]->t[1] = t_transformed[i]->t[1];
			t_viewed[i]->t[2] = t_transformed[i]->t[2];
			int nclippedtriangles = 0;
			t_tri clipped[2];
			nclippedtriangles = t_clipplane((t_vertex){0.0, 0.0, 0.1, 1.0}, (t_vertex){0.0, 0.0, 1.0, 1.0}, *t_viewed[i], &clipped[0], &clipped[1]);
			
			while (n < nclippedtriangles)
			{
				t_projected[i]->vert[0] = matrix_mulvector(e->matProj, clipped[n].vert[0]);
				t_projected[i]->vert[1] = matrix_mulvector(e->matProj, clipped[n].vert[1]);
				t_projected[i]->vert[2] = matrix_mulvector(e->matProj, clipped[n].vert[2]);
				t_projected[i]->t[0] = clipped[n].t[0];
				t_projected[i]->t[1] = clipped[n].t[1];
				t_projected[i]->t[2] = clipped[n].t[2];
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
				pushback(&e->listtri, *t_projected[i]);
			}
			//drawtriangle(e, t_projected[i]);
			//triangle(e, t_projected[i]->vert[0], t_projected[i]->vert[1],t_projected[i]->vert[2], (t_rgba){255,0,0,0});
			n = 0;
		}
	}
	draw(e, e->listtri);
	//drawtriangle(e, e->listtri);
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

int		draw(t_app *e, t_listtri *s)
{
	t_listtri *tmp = s;
	
	if (!s)
		return (0);
	while (tmp)
	{
		t_tri	clipped[2];
		t_listtri *listtri = NULL;

		listtri = s;
		int	newtri = 1;
		int	p = -1;
		while (++p < 4)
		{
			int		tritoadd = 0;
			while (newtri > 0)
			{
				//printf("\nfirst :%f\n", listtri->listtri.vert[0].x);
				t_tri first = listtri->listtri;
				t_listtri *tmp666;
				tmp666 = listtri;
				deletefirst(tmp666);
				newtri--;

				if (p == 0)
					tritoadd = t_clipplane((t_vertex){ 0.0, 0.0, 0.0, 1.0 }, (t_vertex){ 0.0, 1.0, 0.0, 1.0 }, first, &clipped[0], &clipped[1]);break;
				if (p == 1)
					tritoadd = t_clipplane((t_vertex){ 0.0, (double)HEIGHT -1, 0.0, 1.0}, (t_vertex){ 0.0, -1.0, 0.0, 1.0 }, first, &clipped[0], &clipped[1]);break;
				if (p == 2)
					tritoadd = t_clipplane((t_vertex){ 0.0, 0.0, 0.0, 1.0}, (t_vertex){ 1.0, 0.0, 0.0, 1.0}, first, &clipped[0], &clipped[1]);break;
				if (p == 3)
					tritoadd = t_clipplane((t_vertex){ (double)WIDTH - 1, 0.0, 0.0, 1.0}, (t_vertex){ -1.0, 0.0, 0.0, 1.0}, first, &clipped[0], &clipped[1]);break;
				int w = -1;
				while (++w < tritoadd)
				{
					pushback(&listtri, clipped[w]);
				}
			}
			newtri = lstsize(&listtri);
		}
		t_listtri *t;
		t = listtri;
		while (t)
		{
			//triangle(e, t->listtri.vert[0], t->listtri.vert[1],t->listtri.vert[2], (t_rgba){90,0,200,0});
			//_trace(e, t->listtri.vert[0].x, t->listtri.vert[0].y, t->listtri.vert[1].x, t->listtri.vert[1].y, (t_rgba){255, 255, 255 ,0});
			//_trace(e, t->listtri.vert[1].x, t->listtri.vert[1].y, t->listtri.vert[2].x, t->listtri.vert[2].y, (t_rgba){255, 255, 255 ,0});
			//_trace(e, t->listtri.vert[2].x, t->listtri.vert[2].y, t->listtri.vert[0].x, t->listtri.vert[0].y, (t_rgba){255, 255, 255 ,0});
			textured_triangle(e, t->listtri.vert[0].x, t->listtri.vert[0].y, t->listtri.t[0].u, t->listtri.t[0].v,
			t->listtri.vert[1].x, t->listtri.vert[1].y, t->listtri.t[1].u, t->listtri.t[1].v,
			t->listtri.vert[2].x, t->listtri.vert[2].y, t->listtri.t[2].u, t->listtri.t[2].v, *e->tex[0]);
			drawtriangle(e, t);
			t = t->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		drawtriangle(t_app *e, t_listtri *s)
{
	t_listtri *tmp = s;
	
	if (!tmp)
		return (0);
	while (tmp)
	{
		_trace(e, tmp->listtri.vert[0].x, tmp->listtri.vert[0].y, tmp->listtri.vert[1].x, tmp->listtri.vert[1].y, (t_rgba){255, 255, 255 ,0});
		_trace(e, tmp->listtri.vert[1].x, tmp->listtri.vert[1].y, tmp->listtri.vert[2].x, tmp->listtri.vert[2].y, (t_rgba){255, 255, 255 ,0});
		_trace(e, tmp->listtri.vert[2].x, tmp->listtri.vert[2].y, tmp->listtri.vert[0].x, tmp->listtri.vert[0].y, (t_rgba){255, 255, 255 ,0});
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
	w = 384;
	h = 384;
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
	e->tex = (t_mlx **)malloc(sizeof(t_mlx *));
	i = -1;
	while (++i < 1)
		e->tex[i] = (t_mlx *)malloc(sizeof(t_mlx));
	load_texture_from_file(e, 0, "/Users/asaba/ProjectClean/Doom3/wall.xpm");
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
	load_textures(e);
	lmlx_loop(e);
	return (0);
}
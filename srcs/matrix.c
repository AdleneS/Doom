/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:46:24 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 20:29:47 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

void	set_matrix(t_matrix *matrix)
{
	int o;
	int p;
	o = -1;
	while (++o < 4)
	{
		p = -1;
		while (++p < 4)
			matrix->m[o][p] = 0.0;
	}
}
void	initMatrix_X(t_app *e)
{
	//int o;
	//int p;
	//o = -1;
	//while (++o < 4)
	//{
	//	p = -1;
	//	while (++p < 4)
	//		e->matRotX.m[o][p] = 0.0;
	//}
	e->matRotX.m[0][0] = 1.0;
	e->matRotX.m[1][1] = cosf(e->test);
	e->matRotX.m[1][2] = sinf(e->test);
	e->matRotX.m[2][1] = -sinf(e->test);
	e->matRotX.m[2][2] = cosf(e->test);
	e->matRotX.m[3][3] = 1.0;
}

void	initMatrix_Y(t_app *e)
{
	//int o;
	//int p;
	//o = -1;
	//while (++o < 4)
	//{
	//	p = -1;
	//	while (++p < 4)
	//		e->matRotY.m[o][p] = 0.0;
	//}
	e->matRotY.m[0][0] = cosf(e->test);
	e->matRotY.m[0][2] = sinf(e->test);
	e->matRotY.m[2][0] = -sinf(e->test);
	e->matRotY.m[1][1] = 1.0;
	e->matRotY.m[2][2] = cosf(e->test);
	e->matRotY.m[3][3] = 1.0;
}

void	initMatrix_Z(t_app *e)
{
	//int o;
	//int p;
	//o = -1.0;
	//while (++o < 4)
	//{
	//	p = -1;
	//	while (++p < 4)
	//		e->matRotZ.m[o][p] = 0.0;
	//}
	e->matRotZ.m[0][0] = cosf(e->test);
	e->matRotZ.m[0][1] = sinf(e->test);
	e->matRotZ.m[1][0] = -sinf(e->test);
	e->matRotZ.m[1][1] = cosf(e->test);
	e->matRotZ.m[2][2] = 1.0;
	e->matRotZ.m[3][3] = 1.0;
}

t_matrix		matrix_translation(double x, double y, double z)
{
	t_matrix m;
	int o;
	int p;
	o = -1;
	while (++o < 4)
	{
		p = -1;
		while (++p < 4)
			m.m[o][p] = 0.0;
	}
	m.m[0][0] = 1.0;
	m.m[1][1] = 1.0;
	m.m[2][2] = 1.0;
	m.m[3][3] = 1.0;
	m.m[3][0] = x;
	m.m[3][1] = y;
	m.m[3][2] = z;
	return (m);
}

void		init_matrix_proj(t_app *e)
{
	int i;
	int j;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			e->matProj.m[i][j] = 0.0;
	}
	e->matProj.m[0][0] = e->faspectratio * e->ffovrad;
	e->matProj.m[1][1] = e->ffovrad;
	e->matProj.m[2][2] = e->ffar / (e->ffar - e->fnear);
	e->matProj.m[3][2] = (-e->ffar * e->fnear) / (e->ffar - e->fnear);
	e->matProj.m[2][3] = 1.0;
	e->matProj.m[3][3] = 0.0;
}

t_matrix		matrix_mulMatrix(t_matrix m1, t_matrix m2)
{
	t_matrix m;
	int c;
	int r;
	
	c = -1;
	while (++c < 4)
	{
		r = -1;
		while (++r < 4)
			m.m[r][c] = m1.m[r][0] * m2.m[0][c] + m1.m[r][1] * m2.m[1][c] + m1.m[r][2] * m2.m[2][c] + m1.m[r][3] * m2.m[3][c];
	}
	return (m);
}

void		matrix_identity(t_matrix *mat)
{
	//t_matrix	m;
	//int i;
	//int j;
	//i = -1;
	//while (++i < 4)
	//{
	//	j = -1;
	//	while (++j < 4)
	//		e->m_world.m[i][j] = 0.0;
	//}
	mat->m[0][0] = 1.0f;
	mat->m[1][1] = 1.0f;
	mat->m[2][2] = 1.0f;
	mat->m[3][3] = 1.0f;
	//return (m);
}


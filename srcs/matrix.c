/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:46:24 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/26 12:58:51 by asaba       ###    #+. /#+    ###.fr     */
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
	e->matRotX.m[0][0] = 1.0;
	e->matRotX.m[1][1] = cosf(e->test);
	e->matRotX.m[1][2] = sinf(e->test);
	e->matRotX.m[2][1] = -sinf(e->test);
	e->matRotX.m[2][2] = cosf(e->test);
	e->matRotX.m[3][3] = 1.0;
}

void	initMatrix_Y(t_app *e)
{
	e->matRotY.m[0][0] = cosf(e->test);
	e->matRotY.m[0][2] = sinf(e->test);
	e->matRotY.m[2][0] = -sinf(e->test);
	e->matRotY.m[1][1] = 1.0;
	e->matRotY.m[2][2] = cosf(e->test);
	e->matRotY.m[3][3] = 1.0;
}

void	initMatrixCameraRot(t_app *e)
{
	e->matRotCamera.m[0][0] = cosf(e->fYaw);
	e->matRotCamera.m[0][2] = sinf(e->fYaw);
	e->matRotCamera.m[2][0] = -sinf(e->fYaw);
	e->matRotCamera.m[1][1] = 1.0;
	e->matRotCamera.m[2][2] = cosf(e->fYaw);
	e->matRotCamera.m[3][3] = 1.0;
}

void	initMatrix_Z(t_app *e)
{
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
	mat->m[0][0] = 1.0f;
	mat->m[1][1] = 1.0f;
	mat->m[2][2] = 1.0f;
	mat->m[3][3] = 1.0f;
}

t_matrix		m_pointAt(t_vertex pos, t_vertex target, t_vertex up)
{
	t_vertex newForward;
	t_vertex newRight;
	t_vertex newUp;
	t_vertex a;
	t_matrix m;

	newForward = v_sub(target, pos);
	newForward = v_normalize(newForward);

	a = v_mul(newForward, v_dotproduct(up, newForward));
	newUp = v_sub(up, a);
	newUp = v_normalize(newUp);
	
	newRight = v_crossprod(newUp, newForward);

	m.m[0][0] = newRight.x;		m.m[0][1] = newRight.y;		m.m[0][2] = newRight.z;		m.m[0][3] = 0.0f;
	m.m[1][0] = newUp.x;		m.m[1][1] = newUp.y;		m.m[1][2] = newUp.z;		m.m[1][3] = 0.0f;
	m.m[2][0] = newForward.x;	m.m[2][1] = newForward.y;	m.m[2][2] = newForward.z;	m.m[2][3] = 0.0f;
	m.m[3][0] = pos.x;			m.m[3][1] = pos.y;			m.m[3][2] = pos.z;			m.m[3][3] = 1.0f;
	return m;
}

t_matrix	m_quickInverse(t_matrix m)
	{
		t_matrix matrix;
		matrix.m[0][0] = m.m[0][0]; matrix.m[0][1] = m.m[1][0]; matrix.m[0][2] = m.m[2][0]; matrix.m[0][3] = 0.0f;
		matrix.m[1][0] = m.m[0][1]; matrix.m[1][1] = m.m[1][1]; matrix.m[1][2] = m.m[2][1]; matrix.m[1][3] = 0.0f;
		matrix.m[2][0] = m.m[0][2]; matrix.m[2][1] = m.m[1][2]; matrix.m[2][2] = m.m[2][2]; matrix.m[2][3] = 0.0f;
		matrix.m[3][0] = -(m.m[3][0] * matrix.m[0][0] + m.m[3][1] * matrix.m[1][0] + m.m[3][2] * matrix.m[2][0]);
		matrix.m[3][1] = -(m.m[3][0] * matrix.m[0][1] + m.m[3][1] * matrix.m[1][1] + m.m[3][2] * matrix.m[2][1]);
		matrix.m[3][2] = -(m.m[3][0] * matrix.m[0][2] + m.m[3][1] * matrix.m[1][2] + m.m[3][2] * matrix.m[2][2]);
		matrix.m[3][3] = 1.0f;
		return matrix;
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mesh.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 15:12:06 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:13:48 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

void		createcube(t_app *e)
{
	*e->mesh =
(t_mesh){
			{
				//SUD
				{{{0.0, 0.0, 0.0},	{0.0, 1.0, 0.0},	{1.0, 1.0, 0.0}}},
				{{{0.0, 0.0, 0.0},	{1.0, 1.0, 0.0},	{1.0, 0.0, 0.0}}},
				//EST
				{{{1.0, 0.0, 0.0},	{1.0, 1.0, 0.0},	{1.0, 1.0, 1.0}}},
				{{{1.0, 0.0, 0.0},	{1.0, 1.0, 1.0},	{1.0, 0.0, 1.0}}},
				//NORD
				{{{1.0, 0.0, 1.0},	{1.0, 1.0, 1.0},	{0.0, 1.0, 1.0}}},
				{{{1.0, 0.0, 1.0},	{0.0, 1.0, 1.0},	{0.0, 0.0, 1.0}}},
				//OUEST
				{{{0.0, 0.0, 1.0},	{0.0, 1.0, 1.0},	{0.0, 1.0, 0.0}}},
				{{{0.0, 0.0, 1.0},	{0.0, 1.0, 0.0},	{0.0, 0.0, 0.0}}},
				//HAUT
				{{{0.0, 1.0, 0.0},	{0.0, 1.0, 1.0},	{1.0, 1.0, 1.0}}},
				{{{0.0, 1.0, 0.0},	{1.0, 1.0, 1.0},	{1.0, 1.0, 0.0}}},
				//BAS
				{{{1.0, 0.0, 1.0},	{0.0, 0.0, 1.0},	{0.0, 0.0, 0.0}}},
				{{{1.0, 0.0, 1.0},	{0.0, 0.0, 0.0},	{1.0, 0.0, 0.0}}},
			}
	};
}

void		fmatrix(t_app *e)
{
	double fnear = 0.1;
	double ffar = 1000.0;
	double ffov = 90.0;
	double faspectratio = (double)HEIGHT / WIDTH;
	double ffovrad = 1.0 / tanf(ffov * 0.5 / 180 * 3.14159);
	int i;
	int j;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			e->matrix->m[i][j] = 0;
	}
	e->matrix->m[0][0] = faspectratio * ffovrad;
	e->matrix->m[1][1] = ffovrad;
	e->matrix->m[2][2] = ffar / (ffar - fnear);
	e->matrix->m[3][2] = (-ffar * fnear) / (ffar - fnear);
	e->matrix->m[2][3] = 1;


}

void		mulitplymatrix(t_vertex i, t_vertex *o, t_matrix *matrix)
{
	double w;

	o->x = i.x * matrix->m[0][0] + i.y * matrix->m[1][0] + i.z * matrix->m[2][0] + matrix->m[3][0];
	o->y = i.x * matrix->m[0][1] + i.y * matrix->m[1][1] + i.z * matrix->m[2][1] + matrix->m[3][1];
	o->z = i.x * matrix->m[0][2] + i.y * matrix->m[1][2] + i.z * matrix->m[2][2] + matrix->m[3][2];
	w = i.x * matrix->m[0][3] + i.y * matrix->m[1][3] + i.z * matrix->m[2][3] + matrix->m[3][3];
	//printf("%f \n", o->x);
	if (w)
	{
		o->x /= (double)w;
		o->y /= (double)w;
		o->z /= (double)w;
	}
	//printf("%f \n",i.x);
	//printf("%f \n",o->x);
	//printf("%f  ||  ", o->y);
	//printf("%f  ||  ", o->x);
	//printf("%f\n", o->z);
}
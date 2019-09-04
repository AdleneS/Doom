/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mesh.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 15:12:06 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/09/02 14:26:02 by asaba       ###    #+. /#+    ###.fr     */
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
				{{{0.0, 0.0, 0.0, 1.0},	{0.0, 1.0, 0.0, 1.0},	{1.0, 1.0, 0.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{0.0, 0.0, 0.0, 1.0},	{1.0, 1.0, 0.0, 1.0},	{1.0, 0.0, 0.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
				//EST
				{{{1.0, 0.0, 0.0, 1.0},	{1.0, 1.0, 0.0, 1.0},	{1.0, 1.0, 1.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{1.0, 0.0, 0.0, 1.0},	{1.0, 1.0, 1.0, 1.0},	{1.0, 0.0, 1.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
				//NORD
				{{{1.0, 0.0, 1.0, 1.0},	{1.0, 1.0, 1.0, 1.0},	{0.0, 1.0, 1.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{1.0, 0.0, 1.0, 1.0},	{0.0, 1.0, 1.0, 1.0},	{0.0, 0.0, 1.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
				//OUEST
				{{{0.0, 0.0, 1.0, 1.0},	{0.0, 1.0, 1.0, 1.0},	{0.0, 1.0, 0.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{0.0, 0.0, 1.0, 1.0},	{0.0, 1.0, 0.0, 1.0},	{0.0, 0.0, 0.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
				//HAUT
				{{{0.0, 1.0, 0.0, 1.0},	{0.0, 1.0, 1.0, 1.0},	{1.0, 1.0, 1.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{0.0, 1.0, 0.0, 1.0},	{1.0, 1.0, 1.0, 1.0},	{1.0, 1.0, 0.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
				//BAS
				{{{1.0, 0.0, 1.0, 1.0},	{0.0, 0.0, 1.0, 1.0},	{0.0, 0.0, 0.0, 1.0}}, {{0.0, 1.0}, {0.0, 0.0}, {1.0, 0.0}}},
				{{{1.0, 0.0, 1.0, 1.0},	{0.0, 0.0, 0.0, 1.0},	{1.0, 0.0, 0.0, 1.0}}, {{0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}}},
			}
	};
}

t_vertex		matrix_mulvector(t_matrix m, t_vertex i)
{
	t_vertex v;
	v.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + i.w * m.m[3][0];
	v.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + i.w * m.m[3][1];
	v.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + i.w * m.m[3][2];
	v.w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + i.w * m.m[3][3];
	//printf("1:\n");
	//printf("%f * %f = %f  ||  ",i.x, m.m[0][0], i.x * m.m[0][0]);
	//printf("%f * %f = %f  ||  ",i.y, m.m[1][0], i.y * m.m[1][0]);
	//printf("%f * %f = %f\n\n",i.z, m.m[2][0], i.z * m.m[2][0]);
	
	//printf("2:\n");
	//printf("%f * %f = %f  ||  ",i.x, m.m[0][2], i.x * m.m[0][2]);
	//printf("%f * %f = %f  ||  ",i.y, m.m[1][2], i.y * m.m[1][2]);
	//printf("%f * %f = %f\n\n\n\n",i.z, m.m[2][2], i.z * m.m[2][2]);
	//printf("[1][0]: %f  ||  ", m.m[1][0]);
	//printf("[2][0]: %f\n\n", m.m[2][0]);
	//printf("I.x: %f  ||  ", i.x);
	//printf("I.y: %f  ||  ", i.y);
	//printf("I.z: %f  ||  ", i.z);
	//printf("X: %f  ||  ", v.x);
	//printf("Y: %f  ||  ", v.y);
	//printf("Z: %f  ||  ", v.z);
	//printf("W: %f  ||  \n\n", v.w);
	return (v);
}

/*void		mulitplymatrix(t_vertex i, t_vertex *o, t_matrix *matrix)
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
}*/

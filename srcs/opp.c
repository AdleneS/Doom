/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:09:41 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 19:37:11 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

t_vertex		v_add(t_vertex v1, t_vertex v2)
{
	return ((t_vertex){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, 1.0});
}

t_vertex		v_sub(t_vertex v1, t_vertex v2)
{
	return ((t_vertex){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 1.0});
}

t_vertex		v_mul(t_vertex v1, double k)
{
	return ((t_vertex){v1.x * k, v1.y * k, v1.z * k, 1.0});
}
t_vertex		v_div(t_vertex v1, double k)
{
	return ((t_vertex){v1.x / k, v1.y / k, v1.z / k, 1.0});
}

double			v_dotproduct(t_vertex v1, t_vertex v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double v_length(t_vertex v)
{
	return (sqrtf(v_dotproduct(v, v)));
}

t_vertex		v_normalize(t_vertex v)
{
	double l = v_length(v);
	return ((t_vertex){v.x / l, v.y / l, v.z / l, 1.0});
}

t_vertex		v_crossprod(t_vertex v1, t_vertex v2)
{
	t_vertex v;
	
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	v.w = 1.0;
	return (v);
}


/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:09:41 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:02:18 by asaba       ###    #+. /#+    ###.fr     */
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

t_vertex		v_intersectplane(t_vertex plane_p, t_vertex plane_n, t_vertex linestart, t_vertex lineend)
{
	plane_n = v_normalize(plane_n);
	double plane_d = -v_dotproduct(plane_n, plane_p);
	double ad = v_dotproduct(linestart, plane_n);
	double bd = v_dotproduct(lineend, plane_n);
	double t = (-plane_d - ad) / (bd - ad);
	t_vertex linestarttoEnd = (t_vertex){0,0,0,1};
	t_vertex linetointersect = (t_vertex){0,0,0,1};
	linestarttoEnd = v_sub(lineend, linestart);
	linetointersect = v_mul(linestarttoEnd, t);
	return v_add(linestart, linetointersect);
}

double t_distance(t_vertex p, t_vertex plane_n, t_vertex plane_p)
{
	//t_vertex n = v_normalize(p);
	return (plane_n.x * p.x + plane_n.y * p.y + plane_n.z * p.z - v_dotproduct(plane_n, plane_p));
}

int			t_clipplane(t_vertex plane_p, t_vertex plane_n, t_tri in_tri, t_tri *out_tri1, t_tri *out_tri2)
{
	t_vertex	inside_points[3];
	t_vertex	outside_points[3];
	int			n_insidepointcount;
	int			n_outsidepointcount;
	double		d0;
	double		d1;
	double		d2;
	plane_n = v_normalize(plane_n);
	n_insidepointcount = 0;
	n_outsidepointcount = 0;
	d0 = t_distance(in_tri.vert[0], plane_n, plane_p);
	d1 = t_distance(in_tri.vert[1], plane_n, plane_p);
	d2 = t_distance(in_tri.vert[2], plane_n, plane_p);
	if (d0 >=0) inside_points[n_insidepointcount++] = in_tri.vert[0];
	else outside_points[n_outsidepointcount++] = in_tri.vert[0];
	if (d1 >=0) inside_points[n_insidepointcount++] = in_tri.vert[1];
	else outside_points[n_outsidepointcount++] = in_tri.vert[1];
	if (d2 >=0) inside_points[n_insidepointcount++] = in_tri.vert[2];
	else outside_points[n_outsidepointcount++] = in_tri.vert[2];

	printf("\nInside : %d\n", n_insidepointcount);
	printf("Outstide : %d\n", n_outsidepointcount);

	if (n_insidepointcount == 0)
	{
		return (0);
	}
	if (n_insidepointcount == 3)
	{
		*out_tri1 = in_tri;
		return (1);
	}
	if (n_insidepointcount == 1 && n_outsidepointcount == 2)
	{
		out_tri1->vert[0] = inside_points[0];
		out_tri1->vert[1] = v_intersectplane(plane_p, plane_n, inside_points[0], outside_points[0]);
		out_tri1->vert[2] = v_intersectplane(plane_p, plane_n, inside_points[0], outside_points[1]);
		return (1);
	}
	if (n_insidepointcount == 2 && n_outsidepointcount == 1)
	{
		out_tri1->vert[0] = inside_points[0];
		out_tri1->vert[1] = inside_points[1];
		out_tri1->vert[2] = v_intersectplane(plane_p, plane_n, inside_points[0], outside_points[0]);
		
		out_tri2->vert[0] = inside_points[1];
		out_tri2->vert[1] = out_tri1->vert[2];
		out_tri2->vert[2] = v_intersectplane(plane_p, plane_n, inside_points[1], outside_points[0]);
		return (2);
	}
	return (0);
}

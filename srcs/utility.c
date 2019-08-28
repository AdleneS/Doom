/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utility.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 14:54:09 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 13:24:06 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

double		min(double a, double b)
{
	return ((a < b) ? a : b);
}

double		max(double a, double b)
{
	return ((a > b) ? a : b);
}

double		clamp(double a, double mi, double ma)
{
	return (min(max(a, mi), ma));
}
typedef struct		t_bressen
{
	int 			dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;

void _trace(t_app *e, int x0, int y0, int x1, int y1, t_rgba c)
{
	t_bressen b;

	b.dx = abs(x1 - x0);
	b.dy = abs(y1 - y0);
	b.sx = (x0 < x1 ? 1 : -1);
	b.sy = (y0 < y1 ? 1 : -1); 
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
 	while (1)
	{
		lmlx_putpixel(e, x0, y0, c);
		if (x0 == x1 && y0 == y1)
			break;
		b.e2 = b.err;
		if (b.e2 > -b.dx) 
		{
			b.err -= b.dy;
			x0 += b.sx; 
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx; 
			y0 += b.sy;
		}
	}
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:27:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 14:52:39 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "structs.h"
# include "defines.h"
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <time.h>
# include <math.h>
# include <sys/stat.h>

void	lmlx_init(t_app *e);
void	lmlx_putpixel(t_app *e, int x, int y, t_rgba c);
void	lmlx_loop(t_app *e);
void	lmlx_clearimg(t_app *e);

int		main_loop(t_app *e);

void	hook_keys(t_app *e);
int		keyhook_press(int k, t_app *e);
int		keyhook_release(int k, t_app *e);

double		min(double a, double b);
double		max(double a, double b);
double		clamp(double a, double mi, double ma);

int		mouse_move(int x, int y, t_app *e);

void	_trace(t_app *e, int x0, int y0, int x1, int y1, t_rgba c);
void	createcube(t_app *e);
void	fmatrix(t_app *e);
void	mulitplymatrix(t_vertex i, t_vertex *o, t_matrix *matrix);
void	drawtriangle(t_app *e, t_tri *t);

#endif
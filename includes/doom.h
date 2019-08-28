/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:27:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 18:00:48 by asaba       ###    #+. /#+    ###.fr     */
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

void			lmlx_init(t_app *e);
void			lmlx_putpixel(t_app *e, int x, int y, t_rgba c);
void			lmlx_loop(t_app *e);
void			lmlx_clearimg(t_app *e);

int				main_loop(t_app *e);

void			hook_keys(t_app *e);
int				keyhook_press(int k, t_app *e);
int				keyhook_release(int k, t_app *e);

double			min(double a, double b);
double			max(double a, double b);
double			clamp(double a, double mi, double ma);

int				mouse_move(int x, int y, t_app *e);
int				drawtriangle(t_app *e, t_listtri *s);
int				draw(t_app *e, t_listtri *s);

void			_trace(t_app *e, int x0, int y0, int x1, int y1, t_rgba c);
void			createcube(t_app *e);
void			mulitplymatrix(t_vertex i, t_vertex *o, t_matrix *matrix);
void			initMatrix_X(t_app *e);
void			initMatrix_Y(t_app *e);
void			initMatrix_Z(t_app *e);
void			init_matrix_proj(t_app *e);
t_vertex		matrix_mulvector(t_matrix m, t_vertex i);
t_matrix		matrix_mulMatrix(t_matrix m1, t_matrix m2);
t_matrix		matrix_translation(double x, double y, double z);
void			matrix_identity(t_matrix *mat);
t_vertex		v_add(t_vertex v1, t_vertex v2);
t_vertex		v_sub(t_vertex v1, t_vertex v2);
t_vertex		v_mul(t_vertex v1, double k);
t_vertex		v_div(t_vertex v1, double k);
t_vertex		v_normalize(t_vertex v);
t_vertex		v_crossprod(t_vertex v1, t_vertex v2);
void			set_matrix(t_matrix *matrix);
double			v_length(t_vertex v);
double			v_dotproduct(t_vertex v1, t_vertex v2);
t_matrix		m_pointAt(t_vertex pos, t_vertex target, t_vertex up);
t_matrix		m_quickInverse(t_matrix m);
void			initMatrixCameraRot(t_app *e);
int				t_clipplane(t_vertex plane_p, t_vertex plane_n, t_tri in_tri, t_tri *out_tri1, t_tri *out_tri2);
void			triangle(t_app *e, t_vertex t0, t_vertex t1, t_vertex t2, t_rgba color);



#endif
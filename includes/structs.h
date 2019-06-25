/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structs.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:27:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 14:18:19 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_rgba
{	
	int					r;
	int					g;
	int					b;
	int					a;
}						t_rgba;

typedef struct			s_vertex
{	
	double				x;
	double				y;
	double				z;
}						t_vertex;

typedef struct			s_tri
{
	t_vertex			vert[3];
}						t_tri;

typedef struct			s_mesh
{
	t_tri				tri[12];
}						t_mesh;

typedef struct			s_matrix
{
	double				m[4][4];
}						t_matrix;

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*imgptr;
	void				*img;
	char				*imgdata;
	int					size;
	int					endian;
	int					bpp;
}						t_mlx;

typedef struct			s_keypress
{	
	short int			up;
	short int			down;
	short int			left;
	short int			right;
	short int			jump;
}						t_keypress;


typedef struct			s_mouse
{
	int					x;
	int					y;
}						t_mouse;


typedef struct			s_app
{
	struct s_mlx		mlx;
	struct s_keypress	key;
	struct s_mouse		mouse;
	
	struct s_matrix		*matrix;
	struct s_mesh		*mesh;
	struct s_t			*doom;
	struct s_sprite		*sp;
	struct sector		**sector;
	struct s_mlx		**tex;
	short int			currentsector;
	short int			pause;
	double				test;
}						t_app;

 
#endif

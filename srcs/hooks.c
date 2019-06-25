/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:39:09 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:10:39 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** udpate struct depending on which key the user press/release
*/

static void	keys_handle(t_app *e, int key, short int value)
{
	if (key == K_W)
		e->test += 0.5;
	if (key == K_S)
		e->key.down = value;
	if (key == K_D)
		e->key.right = value;
	if (key == K_A)
		e->key.left = value;
	if (key == K_SPACE)
		e->key.jump = value;
}

int			keyhook_press(int k, t_app *e)
{
	if (k == K_ESC)
		exit(0);
	keys_handle(e, k, 1);
	//e->pause = 1;
	return (1);
}

int			keyhook_release(int k, t_app *e)
{
	keys_handle(e, k, 0);
	//e->pause = 0;
	return (1);
}

void		hook_keys(t_app *e)
{
	float mx;
	float my;

	my = 0.0;
	mx = 0.0;
	
	if (e->key.up)
	{

	}
	if (e->key.down)
	{

	}
	if (e->key.right)
	{

	}
	if (e->key.left)
	{

	}
}

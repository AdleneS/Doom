/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:39:09 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 14:41:36 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/doom.h"

static void	keys_handle(t_app *e, int key, short int value)
{
	t_vertex	vForward = v_mul(e->vlookdir, 0.10);
	
	if (key == K_UP)
		e->vcamera.y += 0.10;
	if (key == K_DOWN)
		e->vcamera.y -= 0.10;
	if (key == K_RIGHT)
		e->vcamera.x += 0.10;
	if (key == K_LEFT)
		e->vcamera.x -= 0.10;
		
	if (key == K_W)
		e->vcamera = v_add(e->vcamera, vForward);
	if (key == K_S)
		e->vcamera = v_sub(e->vcamera, vForward);
	if (key == K_A)
		e->fYaw += 0.10;
	if (key == K_D)
		e->fYaw -= 0.10;

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

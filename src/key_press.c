/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_press.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 04:39:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/16 16:41:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		more_event(int keycode, t_env *v)
{
	if (keycode == Q || keycode == W || keycode == E || keycode == A || keycode == S || keycode == D)
		rotations(v, keycode);
	if (keycode == J || keycode == K)
		rotation_camera(v, keycode);
	if (keycode == RIGHT || keycode == LEFT)
		change_x(v, keycode);
	if (keycode == UP || keycode == DOWN)
		change_y(v, keycode);
	if (keycode == MORE || keycode == LESS)
		change_z_iso(v, keycode);
	if (keycode == O || keycode == L)
		zoom(v, keycode);
}

int			key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
	{
		free_env(v);
		exit(0);
	}
	if (keycode)
		v->key[keycode] = 1;
	if (keycode == P)
	{
		free(v->cur);
		parallel_view(v);
	}
	if (keycode == I)
	{
		free(v->cur);
		iso_view(v);
	}
	more_event(keycode, v);
	return (0);
}

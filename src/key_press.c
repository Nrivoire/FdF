/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_press.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 04:39:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 17:17:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			rotations(t_env *v, int keycode)
{
	int		i;

	i = -1;
	if (keycode == W)
		v->ry += 0.1;
	if (keycode == S)
		v->ry -= 0.1;
	if (keycode == A)
		v->rx += 0.1;
	if (keycode == D)
		v->rx -= 0.1;
	while (++i < v->max)
	{
		v->cur[i].z = (v->map[i].y - (v->li * .5)) * sin(v->ry) + \
				v->map[i].z * cos(v->rz);
		v->cur[i].x = (v->map[i].x - (v->col * .5)) * cos(v->rx) + \
				v->map[i].z * sin(v->rz);
		v->cur[i].y = (v->map[i].x - (v->col * .5)) * sin(v->rx) + \
				(v->map[i].y - (v->li * .5)) * cos(v->ry);
	}
	display_map(v);
	return (0);
}

void		more_event(int keycode, t_env *v)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		rotations(v, keycode);
	if (keycode == J || keycode == K)
		rotation_camera(v, keycode);
	if (keycode == RIGHT || keycode == LEFT)
		change_x(v, keycode);
	if (keycode == UP || keycode == DOWN)
		change_y(v, keycode);
	if (keycode == MORE || keycode == LESS)
		change_z(v, keycode);
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

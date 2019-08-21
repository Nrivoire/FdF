/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_press.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 04:39:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 14:05:13 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			red_cross(t_env *v)
{
	free_env(v);
	exit(0);
	return (0);
}

void		get_new_color(t_env *v)
{
	int		i;

	i = -1;
	if (v->cur_color == 100)
		v->cur_color = 0;
	else
		v->cur_color++;
	while (++i < v->max)
	{
		if ((v->map[i].color.r == 255 && v->map[i].color.b == 255 && \
				v->map[i].color.g == 255) || (v->map[i].z == 0))
		{
			v->cur[i].c.r = sin(0.2 * v->cur_color + 0) * 127 + 128;
			v->cur[i].c.g = sin(0.2 * v->cur_color + 2 * M_PI / 3) * 127 + 128;
			v->cur[i].c.b = sin(0.2 * v->cur_color + 4 * M_PI / 3) * 127 + 128;
		}
	}
	display_map(v);
}

void		event_rotation(t_env *v, int keycode)
{
	if (keycode == D)
		v->ry += 0.05;
	if (keycode == A)
		v->ry -= 0.05;
	if (keycode == W)
		v->rx += 0.05;
	if (keycode == S)
		v->rx -= 0.05;
	if (keycode == Q)
		v->rz += 0.05;
	if (keycode == E)
		v->rz -= 0.05;
	display_map(v);
}

void		more_event(int keycode, t_env *v)
{
	if (keycode == NB_1 || keycode == NB_2)
		change_deg(v, keycode);
	if (keycode == NB_4 || keycode == NB_5)
		change_horizon(v, keycode);
	if (keycode == RIGHT || keycode == LEFT)
		change_x(v, keycode);
	if (keycode == UP || keycode == DOWN)
		change_y(v, keycode);
	if (keycode == MORE || keycode == LESS)
		change_z(v, keycode);
}

int			key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
		red_cross(v);
	if (keycode)
		v->key[keycode] = 1;
	if (keycode == O)
		orthogonal_view(v);
	if (keycode == I)
		iso_view(v);
	if (keycode == P)
		conic_view(v);
	if (keycode == K || keycode == L)
		zoom(v, keycode);
	if (keycode == C)
		get_new_color(v);
	if (keycode == V)
		make_color_with_z(v);
	if (keycode == W || keycode == S || keycode == A || keycode == D
			|| keycode == Q || keycode == E)
		event_rotation(v, keycode);
	more_event(keycode, v);
	return (1);
}

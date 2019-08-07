/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 04:39:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 03:23:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			change_y(t_env *v, int keycode)
{
	int		inc;
	int		y;

	inc = -1;
	if (keycode == DOWN)
		y = 10;
	else
		y = -10;
	while (++inc < v->max)
		v->current[inc].my += y;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_x(t_env *v, int keycode)
{
	int		inc;
	int		x;

	inc = -1;
	if (keycode == RIGHT)
		x = 10;
	else
		x = -10;
	while (++inc < v->max)
		v->current[inc].mx += x;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_z(t_env *v, int keycode)
{
	int		i;
	double	z;

	i = -1;
	if (keycode == MORE)
		z = 0.5;
	else
		z = -0.5;
	while (++i < v->max)
	{
		if (v->prev[i].z > 0 || v->prev[i].z < 0)
			v->current[i].mz = v->prev[i].z * z + v->current[i].mz;
	}
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
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
	if (keycode == RIGHT || keycode == LEFT)
		change_x(v, keycode);
	if (keycode == UP || keycode == DOWN)
		change_y(v, keycode);
	if (keycode == P)
	{
		free(v->current);
		parallel_view(v);
	}
	if (keycode == I)
	{
		free(v->current);
		iso_view(v);
	}
	if (keycode == MORE || keycode == LESS)
		change_z(v, keycode);
	return (0);
}

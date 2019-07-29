/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 04:39:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 05:32:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			change_y(t_env *v, int key)
{
	int		inc;
	int		y;

	inc = -1;
	if (key == DOWN)
		y = 10;
	else
		y = -10;
	while (++inc < v->max)
		v->current[inc].my += y;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_x(t_env *v, int key)
{
	int		inc;
	int		x;

	inc = -1;
	if (key == RIGHT)
		x = 10;
	else
		x = -10;
	while (++inc < v->max)
		v->current[inc].mx += x;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_z(t_env *v, int key)
{
	int		i;
	double	z;

	i = -1;
	if (key == MORE)
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

int			refresh(t_env *v)
{
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	return (0);
}

int			key_press(int key, t_env *v)
{
	if (key == RIGHT || key == LEFT)
		change_x(v, key);
	if (key == UP || key == DOWN)
		change_y(v, key);
	if (key == ESC)
	{
		free_env(v);
		exit(0);
	}
	if (key == P)
	{
		free(v->current);
		parallel_view(v);
	}
	if (key == I)
	{
		free(v->current);
		iso_view(v);
	}
	if (key == MORE || key == LESS)
		change_z(v, key);
	if (key == R)
		refresh(v);
	return (0);
}

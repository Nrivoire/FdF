/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:19:25 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 15:44:01 by nrivoire    ###    #+. /#+    ###.fr     */
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
		y = 2;
	else
		y = -2;
	while (++inc < v->max)
		v->cur[inc].y += y;
	display_map(v);
	return (0);
}

int			change_x(t_env *v, int keycode)
{
	int		inc;
	int		x;

	inc = -1;
	if (keycode == RIGHT)
		x = 2;
	else
		x = -2;
	while (++inc < v->max)
		v->cur[inc].x += x;
	display_map(v);
	return (0);
}

int			change_z(t_env *v, int keycode)
{
	int		i;
	double	z;

	i = -1;
	if (keycode == MORE)
		z = 0.6;
	else
		z = -0.6;
	while (++i < v->max)
	{
		if (v->cur[i].z > 0 || v->cur[i].z < 0)
			v->map[i].z = v->cur[i].z * z + v->map[i].z;
	}
	display_map(v);
	return (0);
}

int			rotation_camera(t_env *v, int keycode)
{
	int		i;
	double	r;
	double	tmp_x;
	double	tmp_y;

	i = -1;
	if (keycode == Q)
		r = 0.1;
	else
		r = -0.1;
	while (++i < v->max)
	{
		tmp_x = v->cur[i].x * cos(r) + v->cur[i].y * -sin(r);
		tmp_y = v->cur[i].x * sin(r) + v->cur[i].y * cos(r);
		v->cur[i].x = tmp_x;
		v->cur[i].y = tmp_y;
	}
	display_map(v);
	return (0);
}

int			zoom(t_env *v, int keycode)
{
	double	s;
	int		i;

	i = -1;
	if (keycode == O)
		s = 0.5;
	else
		s = -0.5;
	v->scale += s;
	display_map(v);
	return (0);
}

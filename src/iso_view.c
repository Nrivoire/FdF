/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iso_view.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 03:52:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/10 01:10:25 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				iso_view_x(t_env *v, int inc, double start)
{
	int			x;

	x = (int)(v->prev[inc].x + WIDTH * start) + \
			(v->prev[inc].x - v->prev[inc].y) * v->scale * 2;
	return (x);
}

int				iso_view_y(t_env *v, int inc)
{
	int			y;

	y = (int)(v->prev[inc].x + HEIGHT * 0.2) + \
			(v->prev[inc].x + v->prev[inc].y) * v->scale;
	return (y);
}

t_point			make_iso_view(t_env *v, int inc, double start)
{
	t_point		data;

	data.mz = v->prev[inc].z;
	data.mx = iso_view_x(v, inc, start);
	data.my = iso_view_y(v, inc);
	data.color = v->prev[inc].color;
	return (data);
}

double			start_iso_view(t_env *v)
{
	int			left;
	double		start;

	if (v->li > v->col || v->li == v->col)
		start = 0.5;
	else
		start = 0.35;
	left = v->max - v->col;
	while (iso_view_x(v, left, start) < 50)
		start = start + 0.02;
	return (start);
}

void			iso_view(t_env *v)
{
	int			inc;
	double		start_x;

	inc = v->max;
	v->scale = 50;
	while (iso_view_y(v, v->max - 1) > HEIGHT * 0.8 && v->scale > 1)
		v->scale = v->scale - 0.5;
	start_x = start_iso_view(v);
	while (iso_view_x(v, v->col - 1, start_x) > WIDTH * 0.8 && v->scale > 1)
		v->scale = v->scale - 0.5;
	if (!(v->current = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (--inc > -1)
		v->current[inc] = make_iso_view(v, inc, start_x);
	display_map(v);
}

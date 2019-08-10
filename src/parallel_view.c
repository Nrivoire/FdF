/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parallel_view.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 06:58:20 by loatilem     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 23:44:31 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				parallel_view_x(t_env *v, int inc, double limit)
{
	int			x;

	x = (int)(v->prev[inc].x + WIDTH * limit) + v->prev[inc].x * v->scale;
	return (x);
}

int				parallel_view_y(t_env *v, int inc)
{
	int			y;

	y = (int)(v->prev[inc].y - v->prev[inc].z / 20) * cos(M_PI / 3) + \
			(v->prev[inc].y - v->prev[inc].z / 20) * sin(M_PI / 3) * v->scale;
	y = (y + (HEIGHT * 0.3));
	return (y);
}

t_point			make_parallel_view(t_env *v, int inc, double limit)
{
	t_point		data;

	data.mz = v->prev[inc].z;
	data.mx = parallel_view_x(v, inc, limit);
	data.my = parallel_view_y(v, inc);
	data.color = v->prev[inc].color;
	return (data);
}

double			start_parallel_view(t_env *v)
{
	int			left;
	double		limit;

	if (v->li > v->col || v->li == v->col)
		limit = 0.3;
	else
		limit = 0.2;
	left = v->col * v->li - v->col;
	while (parallel_view_x(v, left, limit) < 50)
		limit = limit + 0.02;
	return (limit);
}

void			parallel_view(t_env *v)
{
	int			inc;
	double		limit_x;

	inc = v->max;
	v->scale = 50;
	while (parallel_view_y(v, v->max - 1) > HEIGHT * 0.8 && v->scale > 1)
		v->scale = v->scale - 0.5;
	limit_x = start_parallel_view(v);
	while (parallel_view_x(v, v->col - 1, limit_x) \
			> WIDTH * 0.8 && v->scale > 1)
		v->scale = v->scale - 0.5;
	if (!(v->current = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (--inc >= 0)
		v->current[inc] = make_parallel_view(v, inc, limit_x);
	display_map(v);
}

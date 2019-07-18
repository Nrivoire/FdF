/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iso_view.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 03:52:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 07:19:59 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				iso_view_x(t_env *v, int inc, double limit)
{
	int			x;

	x = (int)(v->tab[inc].x + WIDTH * limit) + \
			(v->tab[inc].x - v->tab[inc].y) * v->zoom * 2;
	return (x);
}

int				iso_view_y(t_env *v, int inc)
{
	int			y;

	y = (int)(v->tab[inc].x + HEIGHT * 0.2) + \
			(v->tab[inc].x + v->tab[inc].y) * v->zoom;
	return (y);
}

t_point			make_iso_view(t_env *v, int inc, double limit)
{
	t_point		data;

	data.mz = v->tab[inc].z;
	data.mx = iso_view_x(v, inc, limit);
	data.my = iso_view_y(v, inc);
	data.color = v->tab[inc].color;
	return (data);
}

double			start_iso_view(t_env *v)
{
	int			left;
	double		limit;

	if (v->li > v->col || v->li == v->col)
		limit = 0.5;
	else
		limit = 0.35;
	left = v->col * v->li - v->col;
	while (iso_view_x(v, left, limit) < 50)
		limit = limit + 0.02;
	return (limit);
}

void			iso_view(t_env *v)
{
	int			inc;
	double		limit_x;

	inc = v->max;
	v->zoom = 100;
	while (iso_view_y(v, v->max - 1) > HEIGHT * 0.8)
		v->zoom = v->zoom - 0.5;
	limit_x = start_iso_view(v);
	if (!(v->current = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (--inc > -1)
		v->current[inc] = make_iso_view(v, inc, limit_x);
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
}

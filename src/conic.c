/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conic.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 13:34:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 14:04:01 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		change_horizon(t_env *v, int keycode)
{
	if (keycode == NB_4)
		v->horizon++;
	else
		v->horizon--;
	conic_view(v);
}

void		change_deg(t_env *v, int keycode)
{
	if (keycode == NB_1)
		v->var += 0.1;
	else
		v->var -= 0.1;
	conic_view(v);
}

void		conic_view(t_env *v)
{
	int		inc;
	double	deg;

	inc = -1;
	v->view = 2;
	v->scale = 100 / sqrt(pow(v->li, 2) + pow(v->col, 2)) * 10;
	while (++inc < v->max)
	{
		deg = v->map[inc].x * M_PI / (v->col - 1) - M_PI / 2;
		v->cur[inc].x = (v->map[inc].y + v->horizon) * sin(deg * v->var);
		v->cur[inc].y = (v->map[inc].y + v->horizon) * cos(deg * v->var);
	}
	display_map(v);
}

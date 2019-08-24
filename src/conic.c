/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conic.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 13:34:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 15:47:54 by nrivoire    ###    #+. /#+    ###.fr     */
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
}

void		change_deg(t_env *v, int keycode)
{
	if (keycode == NB_1)
		v->var += 0.1;
	else
		v->var -= 0.1;
}

void		conic_view(t_env *v)
{
	int		inc;

	inc = -1;
	v->view = 2;
	v->horizon = 0;
	v->var = 1;
	v->scale = 100 / sqrt(pow(v->li, 2) + pow(v->col, 2)) * 10;
	while (++inc < v->max)
		v->cur[inc].c = v->map[inc].color;
	display_map(v);
}

void		projection_conic(t_env *v)
{
	int		inc;
	double	deg;

	inc = -1;
	while (++inc < v->max)
	{
		deg = v->map[inc].x * M_PI / (v->col - 1) - M_PI / 2;
		v->cur[inc].x = (v->map[inc].y + v->horizon) * sin(deg * v->var);
		v->cur[inc].y = (v->map[inc].y + v->horizon) * cos(deg * v->var) -
				v->map[inc].z * v->elev;
	}
}

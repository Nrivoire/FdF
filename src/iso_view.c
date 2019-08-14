/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iso_view.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 03:52:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 15:10:51 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			make_iso_view(t_env *v, int inc)
{
	t_point		data;

	data.z = v->map[inc].z;
	data.x = (v->map[inc].x - v->map[inc].y) * cos(0.523599);
	data.y = (v->map[inc].x + v->map[inc].y) * sin(0.523599);
	return (data);
}

void			iso_view(t_env *v)
{
	int			inc;

	inc = -1;
	v->view = 1;
	if (v->max > 1000)
		v->scale = 2;
	else
		v->scale = 15;
	if (!(v->cur = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (++inc < v->max)
		v->cur[inc] = make_iso_view(v, inc);
	display_map(v);
}

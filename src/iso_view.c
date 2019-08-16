/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iso_view.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 03:52:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/16 16:41:54 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			make_iso_view(t_env *v, int inc)
{
	t_point		data;

	data.z = v->map[inc].z;
	data.x = ((v->map[inc].x - (v->col * .5)) - (v->map[inc].y - (v->li * .5))) * cos(v->rx);
	data.y = ((v->map[inc].x - (v->col * .5)) + (v->map[inc].y - (v->li * .5))) * sin(v->ry);
	return (data);
}

void			iso_view(t_env *v)
{
	int			inc;

	inc = -1;
	v->view = 1;
	v->rx = 0.523599;
	v->ry = 0.523599;
	v->rz = 0;
	v->scale = 40;
	v->w = WIDTH / 2;
	v->h = HEIGHT / 4;
	if (!(v->cur = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (++inc < v->max)
		v->cur[inc] = make_iso_view(v, inc);
	while ((v->cur[v->max - 1].x * v->scale + v->w) > WIDTH || (v->cur[v->max - 1].y * v->scale + v->h) > HEIGHT)
		v->scale -= 0.5;
	display_map(v);
}

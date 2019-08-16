/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parallel_view.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 06:58:20 by loatilem     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/16 16:35:36 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			make_para_view(t_env *v, int inc)
{
	t_point		data;

	data.z = v->map[inc].z;
	data.x = v->map[inc].x - v->col * 0.5;
	data.y = v->map[inc].y - v->li * 0.5;
	return (data);
}

void			parallel_view(t_env *v)
{
	int			inc;

	inc = -1;
	v->view = 0;
	v->rx = 0;
	v->ry = 0;
	v->rz = 0;
	v->scale = 50;
	v->w = WIDTH / 5;
	v->h = HEIGHT / 4;
	if (!(v->cur = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (++inc < v->max)
		v->cur[inc] = make_para_view(v, inc);
	while ((v->cur[v->max - 1].x * v->scale + v->w) > WIDTH || (v->cur[v->max - 1].y * v->scale + v->h) > HEIGHT)
		v->scale -= 0.5;
	display_map(v);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parallel_view.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 06:58:20 by loatilem     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/13 15:11:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			make_para_view(t_env *v, int inc)
{
	t_point		data;

	data.z = v->map[inc].z;
	data.x = v->map[inc].x;
	data.y = v->map[inc].y;
	return (data);
}

void			parallel_view(t_env *v)
{
	int			inc;
	
	inc = -1;
	v->view = 0;
	if (v->max > 1000)
		v->scale = 2;
	else
		v->scale = 15;
	if (!(v->cur = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	while (++inc < v->max)
		v->cur[inc] = make_para_view(v, inc);
	display_map(v);
}

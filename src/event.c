/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:19:25 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 18:23:00 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		make_color_with_z(t_env *v)
{
	int		i;

	i = -1;
	while (++i < v->max)
	{
		if (v->map[i].z <= 0)
			v->cur[i].c = make_rgb(00, 32, 229, 1);
		if (v->map[i].z > 0 && v->map[i].z < 30)
			v->cur[i].c = make_rgb(46, 159, 30, 1);
		if (v->map[i].z >= 30 && v->map[i].z < 60)
			v->cur[i].c = make_rgb(56, 179, 40, 1);
		if (v->map[i].z >= 60 && v->map[i].z < 80)
			v->cur[i].c = make_rgb(253, 155, 52, 1);
		if (v->map[i].z >= 80 && v->map[i].z < 300)
			v->cur[i].c = make_rgb(105, 62, 6, 1);
		if (v->map[i].z >= 300)
			v->cur[i].c = make_rgb(255, 255, 255, 1);
	}
}

void		change_y(t_env *v, int keycode)
{
	if (keycode == DOWN)
		v->cam_y += 10;
	else
		v->cam_y -= 10;
}

void		change_x(t_env *v, int keycode)
{
	if (keycode == RIGHT)
		v->cam_x += 10;
	else
		v->cam_x -= 10;
}

void		change_z(t_env *v, int keycode)
{
	if (keycode == MORE)
		v->elev += 0.05;
	else
		v->elev -= 0.05;
}

void		zoom(t_env *v, int keycode)
{
	int		i;

	i = -1;
	if (keycode == K)
		v->scale += 0.2;
	else if (v->scale > 1)
		v->scale -= 0.2;
}

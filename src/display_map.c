/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/10 06:04:30 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 15:04:17 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			orthogonal_view(t_env *v)
{
	int			inc;

	inc = -1;
	v->view = 0;
	v->rx = 0;
	v->ry = 0;
	v->rz = 0;
	while (++inc < v->max)
		v->cur[inc].c = v->map[inc].color;
	v->scale = 100 / sqrt(pow(v->li, 2) + pow(v->col, 2)) * 10;
	display_map(v);
}

void			iso_view(t_env *v)
{
	int			inc;

	inc = -1;
	v->view = 1;
	v->rx = 0.823599;
	v->ry = -0.676401;
	v->rz = 0.45;
	while (++inc < v->max)
		v->cur[inc].c = v->map[inc].color;
	v->scale = 100 / sqrt(pow(v->li, 2) + pow(v->col, 2)) * 10;
	display_map(v);
}

void			projection(t_env *v)
{
	int			i;
	double		tmp_x;
	double		tmp_y;
	double		tmp_z;

	i = -1;
	while (++i < v->max)
	{
		tmp_x = v->map[i].x - v->col * 0.5;
		tmp_y = v->map[i].y - v->li * 0.5;
		tmp_z = v->map[i].z * v->elev;
		v->new_x = tmp_x;
		v->new_y = tmp_y * cos(v->rx) + tmp_z * -sin(v->rx);
		v->new_z = tmp_y * sin(v->rx) + tmp_z * cos(v->rx);
		v->new_x = v->new_x * cos(v->ry) + v->new_z * sin(v->ry);
		v->new_z = v->new_x * -sin(v->ry) + v->new_z * cos(v->ry);
		v->cur[i].x = v->new_x;
		v->cur[i].y = v->new_y;
		v->cur[i].z = v->new_z;
	}
}

t_real			make_real(t_env *v, int inc)
{
	t_real		r;
	t_real		t;

	r.x = v->cur[inc].x * v->scale;
	r.y = v->cur[inc].y * v->scale;
	if (v->view == 0 || v->view == 1)
	{
		t.x = r.x;
		t.y = r.y;
		r.x = t.x * cos(v->rz) + t.y * -sin(v->rz);
		r.y = t.x * sin(v->rz) + t.y * cos(v->rz);
	}
	r.x += WIDTH * 0.5 + v->cam_x;
	r.y += HEIGHT * 0.5 + v->cam_y;
	r.color = v->cur[inc].c;
	return (r);
}

void			display_map(t_env *v)
{
	int			inc;

	inc = -1;
	refresh_display(v);
	while (++inc < v->max)
	{
		if (v->map[inc].x % v->col != 0 && v->map[inc].x > 0)
			put_segment(make_real(v, inc - 1), make_real(v, inc), v);
		if (v->map[inc].y % v->li != 0 && v->map[inc].y > 0)
			put_segment(make_real(v, inc - v->col), make_real(v, inc), v);
	}
	make_button1(v);
	make_button2(v);
	make_button3(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	menu(v);
}

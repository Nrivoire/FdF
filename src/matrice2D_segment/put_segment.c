/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_segment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:13:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/10 01:11:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			display_map(t_env *v)
{
	int			inc;

	inc = -1;
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while (++inc < v->max)
	{
		if (v->prev[inc].x % v->col != 0 && v->prev[inc].x > 0)
			put_segment(v->current[inc - 1], v->current[inc], v);
		if (v->prev[inc].y % v->li != 0 && v->prev[inc].y > 0)
			put_segment(v->current[inc - v->col], v->current[inc], v);
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	menu(v);
}

double			percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

t_rgb			gradient(t_bressen b, t_point c, t_point s, t_point e)
{
	double		percentage;

	if (s.color.r == e.color.r && s.color.g == e.color.g && \
			s.color.b == e.color.b)
		return (s.color);
	if (b.dx > b.dy)
		percentage = percent(s.mx, e.mx, c.mx);
	else
		percentage = percent(s.my, e.my, c.my);
	c.color.r = s.color.r + (int)(e.color.r - s.color.r) * percentage;
	c.color.g = s.color.g + (int)(e.color.g - s.color.g) * percentage;
	c.color.b = s.color.b + (int)(e.color.b - s.color.b) * percentage;
	return (c.color);
}

t_bressen		init_bresen(t_point m1, t_point m2)
{
	t_bressen	b;

	b.tmp = m1;
	b.dx = ft_absolu(m2.mx - m1.mx);
	b.dy = ft_absolu(m2.my - m1.my);
	b.sx = (m1.mx < m2.mx ? 1 : -1);
	b.sy = (m1.my < m2.my ? 1 : -1);
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	return (b);
}

void			put_segment(t_point m1, t_point m2, t_env *v)
{
	t_bressen	b;

	m2.my = m2.my - m2.mz;
	m1.my = m1.my - m1.mz;
	b = init_bresen(m1, m2);
	while (1)
	{
		ft_pixel_put(v->mlx->img, m1.mx, m1.my, gradient(b, m1, b.tmp, m2));
		if (m1.mx == m2.mx && m1.my == m2.my)
			break ;
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			m1.mx += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			m1.my += b.sy;
		}
	}
}

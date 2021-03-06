/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_segment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:13:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 18:33:06 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int start, int end, int cur)
{
	double		placement;
	double		distance;

	placement = cur - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

t_rgb			gradient(t_bressen b, t_real c, t_real s, t_real e)
{
	double		percentage;

	if (s.color.r == e.color.r && s.color.g == e.color.g && \
			s.color.b == e.color.b)
		return (s.color);
	if (b.dx > b.dy)
		percentage = percent(s.x, e.x, c.x);
	else
		percentage = percent(s.y, e.y, c.y);
	c.color.r = s.color.r + (int)(e.color.r - s.color.r) * percentage;
	c.color.g = s.color.g + (int)(e.color.g - s.color.g) * percentage;
	c.color.b = s.color.b + (int)(e.color.b - s.color.b) * percentage;
	return (c.color);
}

t_bressen		init_bresen(t_real m1, t_real m2)
{
	t_bressen	b;

	b.dx = ft_absolu(m2.x - m1.x);
	b.dy = ft_absolu(m2.y - m1.y);
	b.sx = (m1.x < m2.x ? 1 : -1);
	b.sy = (m1.y < m2.y ? 1 : -1);
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	return (b);
}

void			put_segment(t_real m1, t_real m2, t_env *v)
{
	t_bressen	b;
	t_real		tmp;

	if ((m1.x < 0 && m1.y < 0 && m2.y < 0 && m2.x < 0) ||
			(m1.x > WIDTH && m1.y > HEIGHT && m2.y > HEIGHT && m2.x > WIDTH))
		return ;
	b = init_bresen(m1, m2);
	tmp = m1;
	while (1)
	{
		ft_pixel_put(v->mlx->img, m1.x, m1.y, gradient(b, m1, tmp, m2));
		if (m1.x == m2.x && m1.y == m2.y)
			break ;
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			m1.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			m1.y += b.sy;
		}
	}
}

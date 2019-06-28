/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ma_put_segment.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:13:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 20:11:29 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ma_put_segment(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	t_bressen		b;

	b.dx = ft_absolu(m2.mx - m1.mx);
	b.dy = ft_absolu(m2.my - m1.my);
	b.sx = (m1.mx < m2.mx ? 1 : -1); 
	b.sy = (m1.my < m2.my ? 1 : -1); 
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
 	while (1)
	{
		ft_pixel_put(v->mlx->img, m1.mx, m1.my, color);
		if (m1.mx == m2.mx && m1.my == m2.my)
			break;
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

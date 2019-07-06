/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ma_put_segment.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:13:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 00:52:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	swap_matrice(t_mat *m1, t_mat *m2)
{
	t_mat		tmp;

	tmp = *m1;
	*m1 = *m2;
	*m2 = tmp;
}

void	strai_horizontal(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	int			tmp;

	if (m1.mx > m2.mx)
		swap_matrice(&m1, &m2);
	tmp = m1.mx - 1;
	while (++tmp <= m2.mx)
		ft_pixel_put(v->mlx->img, tmp, m1.my, color);
}

void	strai_vertical(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	int			tmp;

	if (m1.my > m2.my)
		swap_matrice(&m1, &m2);
	tmp = m1.my - 1;
	while (++tmp <= m2.my)
		ft_pixel_put(v->mlx->img, m1.mx, tmp, color);
}

void	horizontal_kind(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	float		dy;
	float		dx;
	int			tmp;
	float		p;

	if (m1.mx > m2.mx)
		swap_matrice(&m1, &m2);
	tmp = m1.mx - 1;
	dy = ft_absolu(m2.my - m1.my);
	dx = ft_absolu(m2.mx - m1.mx);
	p = m1.my - (m1.mx * (dy / dx));
	while (++tmp <= m2.mx)
		ft_pixel_put(v->mlx->img, tmp, (dy / dx) * tmp + p, color);
}

void	vertical_kind(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	float		dy;
	float		dx;
	float		p;
	int			tmp;

	if (m1.my > m2.my)
		swap_matrice(&m1, &m2);
	tmp = m1.my - 1;
	dy = ft_absolu(m2.my - m1.my);
	dx = ft_absolu(m2.mx - m1.mx);
	p = m1.my - (m1.mx * (dy / dx));
	while (++tmp <= m2.my)
		ft_pixel_put(v->mlx->img, (tmp - p) * (dx / dy), tmp, color);
}

void	ma_put_segment(t_mat m1, t_mat m2, t_env *v, t_rgb color)
{
	float		dy;
	float		dx;

	if (m1.mx == m2.mx)
		strai_vertical(m1, m2, v, color);
	else if (m1.my == m2.my)
		strai_horizontal(m1, m2, v, color);
	else
	{
		dy = ft_absolu(m2.my - m1.my);
		dx = ft_absolu(m2.mx - m1.mx);
		if (dx > dy)
			horizontal_kind(m1, m2, v, color);
		else
			vertical_kind(m1, m2, v, color);
	}
}

// void	ma_put_segment(t_mat m1, t_mat m2, t_env *v, t_rgb color)
// {
// 	t_bressen		b;

// 	b.dx = ft_absolu(m2.mx - m1.mx);
// 	b.dy = ft_absolu(m2.my - m1.my);
// 	b.sx = (m1.mx < m2.mx ? 1 : -1); 
// 	b.sy = (m1.my < m2.my ? 1 : -1); 
// 	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
//  	while (1)
// 	{
// 		ft_pixel_put(v->mlx->img, m1.mx, m1.my, color);
// 		if (m1.mx == m2.mx && m1.my == m2.my)
// 			break;
// 		b.e2 = b.err;
// 		if (b.e2 > -b.dx) 
// 		{
// 			b.err -= b.dy;
// 			m1.mx += b.sx; 
// 		}
// 		if (b.e2 < b.dy)
// 		{
// 			b.err += b.dx; 
// 			m1.my += b.sy;
// 		}
// 	}
// }

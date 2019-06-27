/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strai_vertical.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 21:30:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 16:07:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	strai_vertical(t_cplx c1, t_cplx c2, t_env *v, t_rgb color)
{
	int			tmp;

	if (c1.im > c2.im)
		swap_cplx(&c1, &c2);
	tmp = c1.im - 1;
	while (++tmp <= c2.im)
		ft_pixel_put(v->mlx->img, c1.reel, tmp, color);
}

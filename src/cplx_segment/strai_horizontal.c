/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strai_horizontal.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 21:29:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 23:47:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	strai_horizontal(t_cplx c1, t_cplx c2, t_env *v, t_rgb color)
{
	int			tmp;

	if (c1.reel > c2.reel)
		swap_cplx(&c1, &c2);
	tmp = c1.reel - 1;
	while (++tmp <= c2.reel)
		ft_pixel_put(v->mlx->img, tmp, c1.im, color);
}

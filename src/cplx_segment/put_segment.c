/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_segment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 22:12:02 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 20:02:28 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	put_segment(t_cplx c1, t_cplx c2, t_env *v, t_rgb color)
{
	double		dy;
	double		dx;

	if (c1.reel == c2.reel)
		strai_vertical(c1, c2, v, color);
	else if (c1.im == c2.im)
		strai_horizontal(c1, c2, v, color);
	else
	{
		dy = ft_absolu(c2.im - c1.im);
		dx = ft_absolu(c2.reel - c1.reel);
		if (dx > dy)
			horizontal_kind(c1, c2, v, color);
		else
			vertical_kind(c1, c2, v, color);
	}
}

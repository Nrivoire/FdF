/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_real.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/10 06:04:30 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 15:47:05 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_real			make_real(t_env *v, int inc)
{
	t_real		r;

	r.x = v->cur[inc].x * v->scale + WIDTH / 2 - v->col * 0.5;
	r.y = v->cur[inc].y * v->scale + HEIGHT / 2 - v->li * 0.5;
	r.z = v->map[inc].z;
	r.color = v->map[inc].color;
	return (r);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_real.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/10 06:04:30 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/10 06:04:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_real			make_real(t_env *v, int inc)
{
	t_real		r;

	r.x = v->current[inc].mx;
	r.y = v->current[inc].my;
	r.z = v->current[inc].mz;
	r.color = v->current[inc].color;
	return (r);
}

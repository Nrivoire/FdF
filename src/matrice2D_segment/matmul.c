/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matmul.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:55:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 21:47:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

float	*make_b(t_env *v, int inc)
{
	float	*b;

	b = ft_memalloc(2);
	b[0] = (float)v->tab[inc].x;
	b[1] = (float)v->tab[inc].y;
	//b[2] = (float)v->tab[inc].z;
	return (b);
}

float	*make_a(float radian)
{
	float	*a;

	a = ft_memalloc(4);
	a[0] = cos(radian);
	a[1] = -sin(radian);
	a[2] = sin(radian);
	a[3] = cos(radian);
	//a[4] = cos(radian);
	//a[5] = 0;
	return (a);
}

t_mat	matmul(t_env *v, int inc, float zoom, float radian)
{
	t_mat	matrix;
	float	x;
	float	y;
	float	*a;
	float	*b;

	a = make_a(radian);
	b = make_b(v, inc);
	x = a[0] * b[0] + a[1] * b[1];
	x = (x * zoom) + WIDTH / 3;
	matrix.mx = x;
	y = a[2] * b[0] + a[3] * b[1];
	y = (y * zoom) + HEIGHT / 3 - v->tab[inc].z;
	matrix.my = y;
	return (matrix);
}

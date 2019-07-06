/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:55:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 03:44:46 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

float	*make_b(t_env *v, int inc)
{
	float	*b;

	b = ft_memalloc(2);
	b[0] = v->tab[inc].x;
	//printf("x = %f", v->tab[inc].x);
	b[1] = v->tab[inc].y;
	//printf("y = %f\n", v->tab[inc].y);
	//b[2] = v->tab[inc].z;
	return (b);
}

float	*make_a(float radian)
{
	float	*a;

	a = ft_memalloc(4);
	a[0] = cos(radian);
	a[1] = sin(radian);
	a[2] = sin(radian);
	a[3] = cos(radian);
	//a[4] = 1;
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
	//float	a[4] = {1, 1, 1, 1};
	//float	b[3] = {0, 100, 75};

	a = make_a(radian);
	b = make_b(v, inc);
	x = a[0] * b[0] + a[1] * b[1]; //+ a[2] * b[2];
	//x = v->tab[inc].x;
	matrix.mx = x * zoom;
	printf("x = %f", matrix.mx);
	y = a[3] * b[0] + a[4] * b[1]; //+ a[5] * b[2];
	//y = v->tab[inc].y;
	matrix.my = y * zoom;
	printf("  y = %f\n", matrix.my);
	return (matrix);
}

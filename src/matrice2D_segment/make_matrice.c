/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:55:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 04:40:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

// t_mat	make_matrice(float x, float y, float z)
// {
// 	t_mat		matrice;

// 	matrice.mx = x;
// 	matrice.my = y;
// 	return (matrice);
// }

t_mat	matmul(t_env *v, int inc)
{
	t_mat		matrix;
	float		*a; //float [][] a
	float		*b; //float [][] b
	int			i;
	int			j;
	int			k;
	float		x;
	float		y;

	i = -1;
	x = 0;
	y = 0;
	a = ft_memalloc(6);
	a[0] = 1; //x
	a[1] = 0;  //y
	a[2] = 0;   //z
	a[3] = 0; //x
	a[4] = 1;  //y
	a[5] = 0;   //z
	b = ft_memalloc(3);
	b[0] = v->tab[inc].x;
	b[1] = v->tab[inc].y;
	b[2] = v->tab[inc].z;
	while (a[++i] <= 5)
	{
		k = -1;
		j = -1;
		while (a[++j] <= 3 && b[++k] <= 3)
		{
			x += a[j] * b[k];
			matrix.mx = x;
		}
		k = -1;
		while (a[++j] <= 5 && b[++k] <= 3)
		{
			y = a[j] + b[k];
			matrix.my = y;
		}
	}
	free(a);
	free(b);
	return (matrix);
}

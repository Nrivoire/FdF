/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:55:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 20:51:11 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_mat	make_matrice(double x, double y)
{
	t_mat		matrice;

	matrice.mx = x;
	matrice.my = y;
	return (matrice);
}

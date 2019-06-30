/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 19:55:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 15:22:26 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_mat	make_matrice(double x, double y, double radian, double zoom)
{
	t_mat		matrice;
	double		tmp_x;
	double		tmp_y;

	tmp_x = x * zoom;
	tmp_y = y * zoom;
	matrice.mx = (tmp_x * cos(radian)) + (tmp_y * -sin(radian));
	matrice.my = (tmp_x * sin(radian)) + (tmp_y * cos(radian));
	return (matrice);
}

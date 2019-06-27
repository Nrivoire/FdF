/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_cplx.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 17:11:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 21:23:12 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_cplx	ft_make_cplx(double x, double y, int zoom)
{
	t_cplx		cplx;

	cplx.reel = x * zoom;
	cplx.im = y * zoom;
	return (cplx);
}

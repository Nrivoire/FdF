/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_cplx.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 17:11:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 22:25:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_cplx	ft_make_cplx(double x, double y)
{
	t_cplx		cplx;

	cplx.reel = x;
	cplx.im = y;
	return (cplx);
}

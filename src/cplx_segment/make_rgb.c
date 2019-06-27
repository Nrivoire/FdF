/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_rgb.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 21:00:11 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 22:11:52 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	make_rgb(int r, int g, int b, int a)
{
	t_rgb	content;

	content.r = r;
	content.g = g;
	content.b = b;
	content.a = a;
	return (content);
}

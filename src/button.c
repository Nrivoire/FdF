/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   button.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 22:16:10 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 14:59:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			button_press(int button, int x, int y, t_env *v)
{
	if (button == 1 && x > 10 && x < 220 && y > 20 && y < 60)
		orthogonal_view(v);
	if (button == 1 && x > 10 && x < 220 && y > 80 && y < 120)
		iso_view(v);
	if (button == 1 && x > 10 && x < 220 && y > 140 && y < 180)
		conic_view(v);
	return (0);
}

t_real		make_point(int x, int y, t_rgb color)
{
	t_real	p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}

void		make_button1(t_env *v)
{
	t_real	c1;
	t_real	c2;

	c1 = make_point(10, 20, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 20, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 20, make_rgb(255, 255, 255, 1));
	c2 = make_point(10, 60, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 60, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 60, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(220, 20, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 60, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
}

void		make_button2(t_env *v)
{
	t_real	c1;
	t_real	c2;

	c1 = make_point(10, 80, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 80, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 80, make_rgb(255, 255, 255, 1));
	c2 = make_point(10, 120, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 120, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 120, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(220, 80, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 120, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
}

void		make_button3(t_env *v)
{
	t_real	c1;
	t_real	c2;

	c1 = make_point(10, 140, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 140, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 140, make_rgb(255, 255, 255, 1));
	c2 = make_point(10, 180, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(10, 180, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 180, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
	c1 = make_point(220, 140, make_rgb(255, 255, 255, 1));
	c2 = make_point(220, 180, make_rgb(255, 255, 255, 1));
	put_segment(c1, c2, v);
}

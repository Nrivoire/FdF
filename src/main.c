/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 04:50:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			do_win_and_img(t_env *v)
{
	if (!(v->mlx = malloc(sizeof(t_mlx))))
		ft_error("struct t_mlx malloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
}

t_rgb			get_gradient_color(t_rgb color_m1, t_rgb color_m2)
{
	t_rgb		gradient;

	// if (color_m1.r > color_m2.r)
	// {
	// 	gradient.r = ;
	// }
	
	char resultat[4];
	//printf("%d %d\n", color_m1.r, ft_memcpy(resultat, &color_m1.r, 4));
	gradient = color_m1;
	return (gradient);
}

void			make_segment(t_env *v)
{
	int			inc;
	int			max;
	float		zoom;
	float		radian;

	radian = M_PI/6;
	zoom = 40;

	inc = -1;
	max = v->li * v->col;
	while (++inc < max)
	{
		if ((int)v->tab[inc].x % v->col != 0 && v->tab[inc].x > 0)
			ma_put_segment(matmul(v, inc - 1, zoom, radian), matmul(v, inc, zoom, radian), v, get_gradient_color(v->tab[inc].color, v->tab[inc - 1].color));
		if ((int)v->tab[inc].y % v->li != 0 && v->tab[inc].y > 0)
			ma_put_segment(matmul(v, inc - v->col, zoom, radian), matmul(v, inc, zoom, radian), v, get_gradient_color(v->tab[inc].color, v->tab[inc - v->col].color));
	}
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;
	t_lst		*lst;
	//t_mat		c1;
	//t_mat		c2;
	//t_rgb		color;

	av = 2;
	fd = open(ac[1], O_RDONLY);
	if (!(v = malloc(sizeof(t_env))))
		ft_error("struct t_env malloc error");
	do_win_and_img(v);
	lst = fdf_parsing(v, fd);
	create_struct_tab(lst, v);
	make_segment(v);
	//mlx_mouse_hook(v->mlx->win_ptr, button_press, v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

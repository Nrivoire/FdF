/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 20:09:44 by nrivoire    ###    #+. /#+    ###.fr     */
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

void			make_segment(t_env *v)
{
	int		y;
	int		x;
	y = -1;
	while (++y < v->li)
	{
		x = -1;
		while (++x < v->col)
		{
			if (x % v->col != 0 && x > 0)
				put_segment(ft_make_cplx((x - 1 * 10), (y * 10)), ft_make_cplx((x * 10), (y * 10)), v, v->tab[x + v->li * y].color);
			if (y % v->li != 0 && y > 0)
				put_segment(ft_make_cplx((x * 10), (y - 1 * 10)), ft_make_cplx((x * 10), (y * 10)), v, v->tab[x + v->li * y].color);
		}
	}
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;
	t_lst		*lst;

	av = 2;
	fd = open(ac[1], O_RDONLY);
	if (!(v = malloc(sizeof(t_env))))
		ft_error("struct t_env malloc error");
	do_win_and_img(v);
	lst = fdf_parsing(v, fd);
	create_struct_tab(lst, v);
	make_segment(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

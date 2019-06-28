/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 21:06:34 by nrivoire    ###    #+. /#+    ###.fr     */
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

	int zoom;
	int elev;
	int sx;
	int sy;

	sy = 20; //deplacement vertical
	sx = 200; //deplacement horizontal

	elev = -1; //bougement de l'elevation
	zoom = 20;
	
	y = -1;
	while (++y < v->li)
	{
		x = -1;
		while (++x < v->col)
		{
			if (x % v->col != 0 && x > 0)
				ma_put_segment(make_matrice((x - 1 ) * zoom + sx, ((y ) * zoom + sy) + v->tab[(x - 1) + v->col * y].point * elev), make_matrice((x ) * zoom + sx, ((y) * zoom + sy) + v->tab[x + v->col * y].point * elev), v, v->tab[x + v->col * y].color);
			if (y % v->li != 0 && y > 0)
				ma_put_segment(make_matrice((x ) * zoom + sx, (y - 1) * zoom + sy  + v->tab[x + v->col * (y - 1)].point * elev), make_matrice((x ) * zoom + sx, ((y ) * zoom + sy) + v->tab[x + v->col * y].point * elev), v, v->tab[x + v->col * y].color);
		}
	}
}

// void			make_segment(t_env *v)
// {
// 	int		y;
// 	int		x;
// 	y = -1;
// 	while (++y < v->li)
// 	{
// 		x = -1;
// 		while (++x < v->col)
// 		{
// 			if (x % v->col != 0 && x > 0)
// 				put_segment(ft_make_cplx(x - 1 + 30, y + 25, 20), ft_make_cplx(x + 30, y + 25, 20), v, v->tab[x + v->col * y].color);
// 			if (y % v->li != 0 && y > 0)
// 				put_segment(ft_make_cplx(x + 30, y - 1 + 25, 20), ft_make_cplx(x + 30, y + 25, 20), v, v->tab[x + v->col * y].color);
// 		}
// 	}
// }

// int				button_press(int button, int x, int y, t_env *v)
// {
// 	if (button == 1)
// 	{
// 		v->mouv_x = v->mouv_x + x;
// 		make_segment(v);
// 	}
// 	if (button == 3) //moulinette
// 	{
// 	return (0);
// }

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
	//mlx_mouse_hook(v->mlx->win_ptr, button_press, v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

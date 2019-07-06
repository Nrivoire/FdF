/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 01:50:28 by nrivoire    ###    #+. /#+    ###.fr     */
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
	float	zoom;
	float	radian;

	radian = M_PI/6;
	zoom = 40;

	int inc = -1;
	int	max = v->li * v->col;
	while (++inc < max)
	{
		printf("x = %d %d", v->tab[inc].x, v->col);
		if ((int)v->tab[inc].x % v->col != 0 && v->tab[inc].x > 0)
			ma_put_segment(matmul(v, inc - 1, zoom, radian), matmul(v, inc, zoom, radian), v, v->tab[inc].color);
		printf("   y = %d %d\n", v->tab[inc].y, v->col);
		if ((int)v->tab[inc].y % v->li != 0 && v->tab[inc].y > 0)
			ma_put_segment(matmul(v, inc - v->col, zoom, radian), matmul(v, inc, zoom, radian), v, v->tab[inc].color);
	}
}

// void			make_segment(t_env *v)
// {
// 	int		y;
// 	int		x;

// 	int zoom;
// 	int elev;

// 	// x = scaling_in_x_direction(20, x, y); //deplacement vertical
// 	// y = scaling_in_y_direction(20, x, y); //deplacement horizontal

// 	elev = 1; //bougement de l'elevation
// 	zoom = 20;
	
// 	y = -1;
// 	while (++y < v->li)
// 	{
// 		x = -1;
// 		while (++x < v->col)
// 		{
// 			if (x % v->col != 0 && x > 0)
// 				ma_put_segment(make_matrice((x - 1 ) * zoom , ((y ) * zoom) + v->tab[(x - 1) + v->col * y].z * elev), make_matrice((x ) * zoom, ((y) * zoom) + v->tab[x + v->col * y].z * elev), v, v->tab[x + v->col * y].color);
// 			if (y % v->li != 0 && y > 0)
// 				ma_put_segment(make_matrice((x ) * zoom, (y - 1) * zoom  + v->tab[x + v->col * (y - 1)].z * elev), make_matrice((x ) * zoom, ((y ) * zoom) + v->tab[x + v->col * y].z * elev), v, v->tab[x + v->col * y].color);
// 		}
// 	}
// }

t_mat		make_matrice(float x, float y)
{
	t_mat m;

	m.mx = x;
	m.my = y;
	return (m);
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
	//c1 = make_matrice(300, 600);
	//c2 = make_matrice(500, 200);
	//ma_put_segment(c1, c2, v, color);
	make_segment(v);
	//mlx_mouse_hook(v->mlx->win_ptr, button_press, v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 04:34:52 by nrivoire    ###    #+. /#+    ###.fr     */
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

// void			make_segment(t_env *v)
// {
// 	int elev;

// 	elev = -1; //bougement de l'elevation
// 	int sx, sy;
// 	int	zoom;
// 	double	radian;
	
// //(x * cos(radian)) + (y * -sin(radian));
// //(x * sin(radian)) + (y * cos(radian));

// 	sx = 305;
// 	sy = 200;
// 	radian = M_PI/6;
// 	zoom = 33;

// 	int inc = -1;
// 	int	max = v->li * v->col;
// 	while (++inc < max)
// 	{
// 		if (v->tab[inc].x % v->col != 0 && v->tab[inc].x > 0)
// 			ma_put_segment(make_matrice(v->tab[inc].x - 1, v->tab[inc].y, zoom), make_matrice(v->tab[inc].x, v->tab[inc].y, zoom), v, v->tab[inc].color);
// 		if (v->tab[inc].y % v->li != 0 && v->tab[inc].y > 0)
// 			ma_put_segment(make_matrice(v->tab[inc].x, v->tab[inc].y - 1, zoom), make_matrice(v->tab[inc].x, v->tab[inc].y, zoom), v, v->tab[inc].color);
// 	}
// }

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
	//make_segment(v);
	//mlx_mouse_hook(v->mlx->win_ptr, button_press, v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

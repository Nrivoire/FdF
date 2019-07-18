/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 08:03:14 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			change_y(t_env *v, int key)
{
	int		inc;
	int		y;

	inc = -1;
	if (key == DOWN)
		y = 10;
	else
		y = -10;
	while (++inc < v->max)
		v->current[inc].my += y;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_x(t_env *v, int key)
{
	int		inc;
	int		x;

	inc = -1;
	if (key == RIGHT)
		x = 10;
	else
		x = -10;
	while (++inc < v->max)
		v->current[inc].mx += x;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			change_z(t_env *v, int key)
{
	int		i;
	double	z;

	i = -1;
	if (key == MORE)
		z = 0.5;
	else
		z = -0.5;
	while (++i < v->max)
	{
		if (v->tab[i].z > 0 || v->tab[i].z < 0)
			v->current[i].mz = v->tab[i].z * z + v->current[i].mz;
	}
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	display_map(v);
	return (0);
}

int			key_press(int key, t_env *v)
{
	if (key == RIGHT || key == LEFT)
		change_x(v, key);
	if (key == UP || key == DOWN)
		change_y(v, key);
	if (key == P)
		parallel_view(v);
	if (key == ESC)
		exit(0);
	if (key == I)
		iso_view(v);
	if (key == MORE || key == LESS)
		change_z(v, key);
	return (0);
}

int			red_cross(void)
{
	exit(0);
	return (0);
}

int			main(int av, char **ac)
{
	t_env	*v;
	int		fd;

	av = 2;
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	fdf_parsing(v, fd);
	//exit(0);
	display_map(v);
	mlx_key_hook(v->mlx->win_ptr, key_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	free(v);
}

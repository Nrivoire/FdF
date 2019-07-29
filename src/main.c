/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 05:32:58 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		free_env(t_env *v)
{
	if (v)
	{
		if (v->prev)
			free(v->prev);
		if (v->current)
			free(v->current);
		if (v->mlx)
		{
			if (v->mlx->mlx_ptr)
				free(v->mlx->mlx_ptr);
			if (v->mlx->win_ptr)
				free(v->mlx->win_ptr);
			free(v->mlx);
		}
		if (v->img)
		{
			if (v->img->ptr)
				free(v->img->ptr);
			if (v->img->img_tmp)
				free(v->img->img_tmp);
			if (v->img->img)
				free(v->img->img);
			free(v->img);
		}
	}
}

int			red_cross(t_env *v)
{
	free_env(v);
	exit(0);
	return (0);
}

int			main(int av, char **ac)
{
	t_env	*v;
	int		fd;

	if (av != 2)
		ft_error("usage : ./fdf map_sample.fdf");
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	fdf_parsing(v, fd);
	v->max = v->col * v->li;
	iso_view(v);
	mlx_key_hook(v->mlx->win_ptr, key_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	free_env(v);
	return (0);
}

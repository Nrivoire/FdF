/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 16:25:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 19:01:07 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		free_env(t_env *v)
{
	if (v)
	{
		if (v->map)
			free(v->map);
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

void		menu(t_env *v)
{
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr, 19, 28,
			0xFFFFFF, "Orthogonal view : O");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr, 22, 88,
			0xFFFFFF, "Isometric view : I");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr, 39, 148,
			0xFFFFFF, "Conic view : P");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			10, 910, 0xFFFFFF, "Play with the conic view : 4, 5 or 1, 2");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			10, 950, 0xFFFFFF, "Try directional keys");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			10, 980, 0xFFFFFF, "Rotate Camera : W, A, S, D, Q, E");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			99, 1010, 0xFFFFFF, "Zoom : more K less L");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			58, 1040, 0xFFFFFF, "Change z : + or -");
	mlx_string_put(v->mlx->mlx_ptr, v->mlx->win_ptr,
			76, 1070, 0xFFFFFF, "Colors : C or V");
}

void		initialization(t_env *v)
{
	if (!(v->cur = (t_point *)malloc(sizeof(t_point) * v->max)))
		return ;
	v->cam_x = 0;
	v->cam_y = 0;
	v->cur_color = 0;
	v->elev = .2;
	v->var = 1;
}

void		refresh_display(t_env *v)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			ft_pixel_put(v->mlx->img, j, i, make_rgb(0, 0, 0, 1));
	}
	if (v->view == 1 || v->view == 0)
		projection(v);
	if (v->view == 2)
		projection_conic(v);
}

int			main(int av, char **ac)
{
	t_env	*v;
	int		fd;
	t_lst	*lst;

	fd = open(ac[1], O_RDONLY);
	if (av != 2 || fd < 0)
		ft_error("usage : ./fdf map_sample.fdf");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	lst = fdf_parsing(v, fd);
	map(lst, v);
	initialization(v);
	iso_view(v);
	mlx_hook(v->mlx->win_ptr, 2, 0, key_press, v);
	mlx_hook(v->mlx->win_ptr, 5, (1L << 2), button_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	free_env(v);
	return (0);
}

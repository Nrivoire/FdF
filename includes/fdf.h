/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 22:07:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 07:58:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1600
# define HEIGHT 1124
# include "keys.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

/*
**------------------------------------------------------------------------------
*/
#include <stdio.h>
/*
**------------------------------------------------------------------------------
*/



/*
**---------------------------------MATRICE 2D-----------------------------------
*/

typedef struct		s_mlx_img
{
	void			*ptr;
	char			*img;
	char			*img_tmp;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				endian;
}					t_mlx_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_img		img;
}					t_mlx;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_point
{
	int				mx;
	int				my;
	int				mz;
	int				view;
	t_rgb			color;
}					t_point;

typedef struct		s_bressen
{
	t_point			tmp;
	int 			dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;

/*
**-----------------------------ENVIRONNEMENT------------------------------------
*/

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	t_rgb			color;
}					t_map;

typedef struct		s_env
{
	float			dx;
	float			dy;
	int				col;
	int				li;
	int				max;
	float			radian;
	float			zoom;
	t_map			*tab;
	t_point			*current;
	t_mlx			*mlx;
	t_mlx_img		*img;
}					t_env;

/*
**----------------------------------MAKE MAP------------------------------------
*/

void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_error(char *str);
int					ft_absolu(int nb);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
t_rgb				hex_rgb(char *hex);
void				put_segment(t_point m1, t_point m2, t_env *v);
void				display_map(t_env *v);

void				check_map(char *line, t_env *v);
void				fdf_parsing(t_env *v, int fd);
void				iso_view(t_env *v);
void				parallel_view(t_env *v);

#endif

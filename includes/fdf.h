/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 22:07:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/16 16:40:04 by nrivoire    ###    #+. /#+    ###.fr     */
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

typedef struct		s_real
{
	int				x;
	int				y;
	int				z;
	t_rgb			color;
}					t_real;

typedef struct		s_bressen
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;
/*
**-----------------------------ENVIRONNEMENT------------------------------------
*/
typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_map
{
	int				x;
	int				y;
	double			z;
	t_rgb			color;
}					t_map;

typedef struct		s_lst
{
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	double			rx;
	double			ry;
	double			rz;
	int				col;
	int				li;
	int				max;
	int				h;
	int				w;
	double			scale;
	int				view;
	t_map			*map;
	t_point			*cur;
	t_mlx			*mlx;
	t_mlx_img		*img;
	int				key[269];
}					t_env;
/*
**----------------------------------MAKE MAP------------------------------------
*/
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_error(char *str);
int					ft_absolu(int nb);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
t_rgb				hex_rgb(char *hex);
t_real				make_real(t_env *v, int inc);
void				display_map(t_env *v);
void				put_segment(t_real m1, t_real m2, t_env *v);

void				check_map(char *line, t_env *v);
void				check_char(t_env *v, char **split, int x);
t_lst				*fdf_parsing(t_env *v, int fd);
void				map(t_lst *elem, t_env *v);

void				iso_view(t_env *v);
void				parallel_view(t_env *v);

int					zoom(t_env *v, int keycode);
int					change_y(t_env *v, int keycode);
int					change_x(t_env *v, int keycode);
int					change_z_iso(t_env *v, int keycode);
int					rotation_camera(t_env *v, int keycode);
int					rotations(t_env *v, int keycode);
int					key_press(int key, t_env *v);

void				free_env(t_env *v);
void				free_tab(char **tab, int n);
void				menu(t_env *v);
void				map(t_lst *elem, t_env *v);

#endif

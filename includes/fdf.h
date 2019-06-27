/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 22:07:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 21:23:21 by nrivoire    ###    #+. /#+    ###.fr     */
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

/*
**-----------------------------STRUCT MAKE SEGMENT------------------------------
*/
typedef struct		s_mlx_img
{
	void			*ptr;
	char			*img;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				endian;
}					t_mlx_img;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_img		img;
}					t_mlx;

typedef struct		s_cplx
{
	double			reel;
	double			im;
}					t_cplx;

/*
**------------------------------------------------------------------------------
*/

typedef struct		s_lst
{
	int				z;
	t_rgb			color;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_point
{
	int				point;
	t_rgb			color;
}					t_point;

typedef struct		s_env
{
	int				col;
	int				li;
	t_point			*tab;
	t_mlx			*mlx;
}					t_env;

/*
**--------------------------------MAKE SEGMENT----------------------------------
*/
void				put_segment(t_cplx c1, t_cplx c2, t_env *v, \
		t_rgb color);
void				strai_vertical(t_cplx c1, t_cplx c2, t_env *v, \
		t_rgb color);
void				strai_horizontal(t_cplx c1, t_cplx c2, t_env *v, \
		t_rgb color);
void				vertical_kind(t_cplx c1, t_cplx c2, t_env *v, \
		t_rgb color);
void				horizontal_kind(t_cplx c1, t_cplx c2, t_env *v, \
		t_rgb color);
void				swap_cplx(t_cplx *c1, t_cplx *c2);
int					ft_absolu(int nb);
void				ft_error(char *str);
t_cplx				ft_make_cplx(double x, double y, int zoom);

void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
t_rgb				make_rgb(int r, int g, int b, int a);
t_rgb				hex_rgb(char *hex);

/*
**----------------------------------MAKE MAP------------------------------------
*/
void				lstdel(t_lst *lst);
void				add_elem(t_lst **elem, int z, t_rgb color);

t_lst				*fdf_parsing(t_env *v, int fd);
void				create_struct_tab(t_lst *lst, t_env *v);

#endif

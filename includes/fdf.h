/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 22:07:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 18:32:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 128
# define WIDTH 1600
# define HEIGHT 1124
# include "keys.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define LASTEVENTS					35
# define NOEVENTMASK				0L
# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define BUTTONPRESSMASK			(1L<<2)
# define BUTTONRELEASEMASK			(1L<<3)
# define ENTERWINDOWMASK			(1L<<4)
# define LEAVEWINDOWMASK			(1L<<5)
# define POINTERMOTIONMASK			(1L<<6)
# define POINTERMOTIONHINTMASK		(1L<<7)
# define BUTTON1MOTIONMASK			(1L<<8)
# define BUTTON2MOTIONMASK			(1L<<9)
# define BUTTON3MOTIONMASK			(1L<<10)
# define BUTTON4MOTIONMASK			(1L<<11)
# define BUTTON5MOTIONMASK			(1L<<12)
# define BUTTONMOTIONMASK			(1L<<13)
# define KRYMAPSTATEMASK			(1L<<14)
# define EXPOSUREMASK				(1L<<15)
# define VISIBILITYCHANGEMASK		(1L<<16)
# define STRUCTURENOTIFYMASK		(1L<<17)
# define RESIZEREDIRECTMASK			(1L<<18)
# define SUBSTRUCTURENOTIFYMASK		(1L<<19)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK			(1L<<21)
# define PROPERTYCHANGEMASK			(1L<<22)
# define COLORMAPCHANGEMASK			(1L<<23)
# define OWNERGRABBUTTONMASK		(1L<<24)

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
	t_rgb			c;
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
	double			cam_x;
	double			cam_y;
	double			new_z;
	double			new_x;
	double			new_y;
	double			elev;
	double			var;
	int				horizon;
	int				col;
	int				li;
	int				max;
	int				h;
	int				w;
	double			scale;
	int				view;
	int				cur_color;
	t_map			*map;
	t_point			*cur;
	t_mlx			*mlx;
	t_mlx_img		*img;
	int				key[269];
}					t_env;
/*
**----------------------------------MAKE MAP------------------------------------
*/
int					get_next_line(const int fd, char **line);
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_error(char *str);
int					ft_absolu(int nb);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
t_rgb				hex_rgb(char *hex);
t_real				make_real(t_env *v, int inc);
t_rgb				make_rgb(int r, int g, int b, int a);
void				make_button1(t_env *v);
void				make_button2(t_env *v);
void				make_button3(t_env *v);
int					button_press(int button, int x, int y, t_env *v);
void				display_map(t_env *v);
void				put_segment(t_real m1, t_real m2, t_env *v);

void				check_map(char *line, t_env *v);
void				check_char(t_env *v, char **split, int x);
t_lst				*fdf_parsing(t_env *v, int fd);
void				map(t_lst *elem, t_env *v);

void				iso_view(t_env *v);
void				orthogonal_view(t_env *v);
void				conic_view(t_env *v);
void				projection(t_env *v);
void				projection_conic(t_env *v);
void				refresh_display(t_env *v);

void				zoom(t_env *v, int keycode);
void				change_y(t_env *v, int keycode);
void				change_x(t_env *v, int keycode);
void				change_z(t_env *v, int keycode);
void				change_deg(t_env *v, int keycode);
void				change_horizon(t_env *v, int keycode);
void				make_color_with_z(t_env *v);
int					key_press(int key, t_env *v);

void				free_env(t_env *v);
int					red_cross(t_env *v);
void				free_tab(char **tab, int n);
void				menu(t_env *v);
void				map(t_lst *elem, t_env *v);

#endif

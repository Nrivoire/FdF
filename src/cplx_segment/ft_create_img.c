/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_img.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 18:55:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 17:57:44 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	img->ptr = mlx_new_image(ptr, w, h);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian);
	img->width = w;
	img->height = h;
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hex_rgb.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:51:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 23:33:05 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char		*make_hex(char *hex)
{
	int			len;
	char		*tmp;
	int			i;

	i = -1;
	len = ft_strlen(hex);
	if (!hex)
		return (ft_strdup("0xFFFFFF"));
	tmp = ft_strnew(8);
	while (hex[++i])
		tmp[i] = hex[i];
	i--;
	while (++i < len)
		tmp[i] = tmp[i - 1];
	return (tmp);
}

t_rgb		hex_rgb(char *hex)
{
	t_rgb		color;

	hex = make_hex(hex);
	color.r = hex[2] + hex[3] * 16;
	color.g = hex[4] + hex[5] * 16;
	color.b = hex[6] + hex[7] * 16;
	free(hex);
	return (color);
}

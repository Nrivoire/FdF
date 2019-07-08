/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hex_rgb.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:51:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 21:42:50 by nrivoire    ###    #+. /#+    ###.fr     */
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

int			ctohex(char c)
{
	int			hex;

	if (c >= '0' && c <= '9')
		hex = (int)c - 48;
	if (c == 'A' || c == 'a')
		hex = 10;
	if (c == 'B' || c == 'b')
		hex = 11;
	if (c == 'C' || c == 'c')
		hex = 12;
	if (c == 'D' || c == 'd')
		hex = 13;
	if (c == 'E' || c == 'e')
		hex = 14;
	if (c == 'F' || c == 'f')
		hex = 15;
	return (hex);
}

t_rgb		hex_rgb(char *hex)
{
	t_rgb		color;

	hex = make_hex(hex);
	color.r = ctohex(hex[2])+ ctohex(hex[3]) * 16;
	printf("r = %d  ",color.r);
	color.g = ctohex(hex[4])+ ctohex(hex[5]) * 16;
	printf("g = %d  ",color.g);
	color.b = ctohex(hex[6])+ ctohex(hex[7]) * 16;
	printf("b = %d\n",color.b);
	free(hex);
	return (color);
}

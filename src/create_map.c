/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_map.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:09:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 18:34:38 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_map		create_map(char *split, int x, int y, char *d)
{
	t_map	data;

	data.z = ft_atoi(split);
	data.color = hex_rgb(d ? d : "0xFFFFFF");
	data.x = x;
	data.y = y;
	return (data);
}

void		map(t_lst *elem, t_env *v)
{
	int		x;
	int		y;
	int		i;
	char	**split;

	v->max = v->li * v->col;
	if (!(v->map = malloc(sizeof(t_map) * v->max)))
		return ;
	y = -1;
	i = -1;
	while (++y < v->li && elem)
	{
		if (!(split = ft_strsplit(elem->line, ' ')))
			ft_error("Error");
		x = -1;
		while (++x < v->col && ++i < v->max)
		{
			v->map[i] = create_map(split[x], x, y, ft_strchr(split[x], ','));
			check_char(v, split, x);
		}
		elem = elem->next;
		if (split)
			free_tab(split, v->col);
	}
}

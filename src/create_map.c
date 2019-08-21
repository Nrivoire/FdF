/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_map.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:09:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 17:56:03 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		max_min_z(t_env *v)
{
	int		i;

	i = -1;
	v->min_z = 1;
	v->max_z = 0;
	while (++i < v->max)
	{
		if (v->map[i].z > v->max_z)
			v->max_z = v->map[i].z;
		if (v->map[i].z < v->min_z)
			v->min_z = v->map[i].z;
	}
}

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
		split = ft_strsplit(elem->line, ' ');
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
	max_min_z(v);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 12:46:33 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 05:32:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			free_tab(char **tab, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_strdel(&tab[i]);
	free(tab);
}

t_map			create_map(char **split, int x, int y, char *d)
{
	t_map		data;

	data.z = ft_atoi(split[x]);
	data.color = hex_rgb(d ? d : "0xFFFFFF");
	data.x = x;
	data.y = y;
	return (data);
}

t_map			*enlarge(t_env *v, int size, int inc)
{
	t_map		*maptmp;
	int			i;

	i = -1;
	if (!(maptmp = (t_map *)ft_memalloc(sizeof(t_map) * (size + 1000))))
		return (t_map*)(NULL);
	while (++i <= inc)
	{
		maptmp[i].x = v->prev[i].x;
		maptmp[i].y = v->prev[i].y;
		maptmp[i].z = v->prev[i].z;
		maptmp[i].color = v->prev[i].color;
	}
	free(v->prev);
	return (maptmp);
}

void			do_parsing(t_env *v, char *line, int *inc)
{
	char		**split;
	char		*d;
	int			x;

	split = ft_strsplit(line, ' ');
	ft_strdel(&line);
	x = -1;
	while (++x < v->col)
	{
		check_char(v, split, x);
		d = ft_strchr(split[x], ',');
		v->prev[++(*inc)] = create_map(split, x, v->li, d);
	}
	free_tab(split, v->col);
	v->li++;
	*inc = v->col * v->li - 1;
}

void			fdf_parsing(t_env *v, int fd)
{
	char		*line;
	int			size;
	int			inc;

	v->li = 0;
	v->col = 0;
	size = 1000;
	inc = -1;
	if (!(v->prev = (t_map *)ft_memalloc(sizeof(t_map) * size)))
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		check_map(line, v);
		if (inc >= size)
		{
			v->prev = enlarge(v, size, inc);
			size = size + 1000;
		}
		do_parsing(v, line, &inc);
	}
}

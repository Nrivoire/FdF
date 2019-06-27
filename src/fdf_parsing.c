/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 12:46:33 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 15:58:40 by nrivoire    ###    #+. /#+    ###.fr     */
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

static size_t	ft_count_point(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			j = 1;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

void			check_map(char *line, t_env *v)
{
	if (v->col == 0)
		v->col = ft_count_point(line, ' ');
	if (ft_count_point(line, ' ') != (size_t)v->col)
	{
		ft_strdel(&line);
		ft_error("Not a valid map.");
	}
}

t_lst			*fdf_parsing(t_env *v, int fd)
{
	char		*line;
	char		**tab;
	int			i;
	char		*d;
	t_lst		*begin;

	begin = NULL;
	v->li = 0;
	v->col = 0;
	while (get_next_line(fd, &line) == 1)
	{
		check_map(line, v);
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i = -1;
		v->li++;
		while (++i < v->col)
		{
			d = ft_strchr(tab[i], ',');
			add_elem(&begin, ft_atoi(tab[i]), hex_rgb(d ? d + 1 : "0xFFFFFF"));
		}
		free_tab(tab, v->col);
	}
	return (begin);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 07:57:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 12:56:54 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			check_char(t_env *v, char **split, int x)
{
	int			i;

	i = -1;
	while (split[x][++i] != ',' && split[x][i] != '\0')
	{
		if (ft_isalpha(split[x][i]) == 1)
		{
			free_tab(split, v->col);
			ft_error("Not a valid map.\n");
		}
	}
}

static size_t	ft_count_map(char const *s, char c)
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
		v->col = ft_count_map(line, ' ');
	if (ft_count_map(line, ' ') != (size_t)v->col || \
			ft_count_map(line, ' ') == 0)
	{
		ft_strdel(&line);
		ft_error("Not a valid map. The map must be a rectangle.");
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 12:46:33 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/13 14:32:35 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		add_elem(t_lst **elem, char *line)
{
	t_lst	*new;
	t_lst	*tmp;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_error("Error malloc lst");
	new->line = line;
	new->next = NULL;
	if (*elem == NULL)
		*elem = new;
	else
	{
		tmp = *elem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		lstdel(t_lst *lst)
{
	if (lst->next)
		lstdel(lst->next);
	free(lst);
}

void		free_tab(char **tab, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_strdel(&tab[i]);
	free(tab);
}

t_lst		*fdf_parsing(t_env *v, int fd)
{
	char	*line;
	t_lst	*lst;

	lst = NULL;
	v->li = 0;
	v->col = 0;
	while (get_next_line(fd, &line) == 1)
	{
		check_map(line, v);
		v->li++;
		add_elem(&lst, line);
	}
	return (lst);
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
			v->map[i] = create_map(split[x], x, y, ft_strchr(split[x], ','));
		elem = elem->next;
		free_tab(split, v->col);
	}
	//lstdel(elem);
}

// void			free_tab(char **tab, int n)
// {
// 	int			i;

// 	i = -1;
// 	while (++i < n)
// 		ft_strdel(&tab[i]);
// 	free(tab);
// }

// t_map		create_map(char **split, int x, int y, char *d)
// {
// 	t_map		data;

// 	data.z = ft_atoi(split[x]);
// 	data.color = hex_rgb(d ? d : "0xFFFFFF");
// 	data.x = x;
// 	data.y = y;
// 	return (data);
// }

// t_map			*enlarge(t_env *v, int size, int inc)
// {
// 	t_map		*maptmp;
// 	int			i;

// 	i = -1;
// 	if (!(maptmp = (t_map *)ft_memalloc(sizeof(t_map) * (size + 1000))))
// 		return (t_map*)(NULL);
// 	while (++i <= inc)
// 	{
// 		maptmp[i].x = v->prev[i].x;
// 		maptmp[i].y = v->prev[i].y;
// 		maptmp[i].z = v->prev[i].z;
// 		maptmp[i].color = v->prev[i].color;
// 	}
// 	free(v->prev);
// 	return (maptmp);
// }

// void			do_parsing(t_env *v, char *line, int *inc)
// {
// 	char		**split;
// 	char		*d;
// 	int			x;

// 	split = ft_strsplit(line, ' ');
// 	ft_strdel(&line);
// 	x = -1;
// 	while (++x < v->col)
// 	{
// 		check_char(v, split, x);
// 		d = ft_strchr(split[x], ',');
// 		v->prev[++(*inc)] = create_map(split, x, v->li, d);
// 	}
// 	free_tab(split, v->col);
// 	v->li++;
// 	*inc = v->col * v->li - 1;
// }

// void			fdf_parsing(t_env *v, int fd)
// {
// 	char		*line;
// 	int			size;
// 	int			inc;

// 	v->li = 0;
// 	v->col = 0;
// 	size = 1000;
// 	inc = -1;
// 	if (!(v->prev = (t_map *)ft_memalloc(sizeof(t_map) * size)))
// 		return ;
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		check_map(line, v);
// 		if (inc >= size)
// 		{
// 			v->prev = enlarge(v, size, inc);
// 			size = size + 1000;
// 		}
// 		do_parsing(v, line, &inc);
// 	}
// }

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 12:46:33 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 15:09:45 by nrivoire    ###    #+. /#+    ###.fr     */
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

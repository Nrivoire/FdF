/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 12:33:47 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 14:57:59 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		add_elem(t_lst **elem, int z, t_rgb color)
{
	t_lst	*new;
	t_lst	*tmp;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_error("error");
	new->z = z;
	new->color = color;
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

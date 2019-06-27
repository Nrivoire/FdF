/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 17:51:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 17:18:14 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			create_point(t_lst *lst)
{
	t_point		data;

	data.point = lst->z;
	data.color = lst->color;
	return (data);
}

void			create_struct_tab(t_lst *lst, t_env *v)
{
	int			max;
	int			inc;
	t_lst		*tmp;

	tmp = lst;
	max = v->li * v->col;
	inc = -1;
	if (!(v->tab = (t_point *)malloc(sizeof(t_point) * max)))
		return ;
	while (++inc <= max && tmp)
	{
		v->tab[inc] = create_point(tmp);
		tmp = tmp->next;
	}
	lstdel(lst);
}

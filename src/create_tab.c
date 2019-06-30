/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 17:51:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 12:09:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			create_point(t_lst *lst, int x, int y)
{
	t_point		data;

	data.z = lst->z;
	data.color = lst->color;
	data.x = x;
	data.y = y;
	return (data);
}

void			create_struct_tab(t_lst *lst, t_env *v)
{
	int			max;
	int			inc;
	int			x;
	int			y;
	t_lst		*tmp;

	tmp = lst;
	max = v->li * v->col;
	inc = -1;
	if (!(v->tab = (t_point *)malloc(sizeof(t_point) * max)))
		return ;
	y = -1;
	while (++y < v->li)
	{
		x = -1;
		while (++x < v->col && ++inc <= max && tmp)
		{
			v->tab[inc] = create_point(tmp, x, y);
			tmp = tmp->next;
		}
	}
	lstdel(lst);
}

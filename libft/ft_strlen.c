/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:29:54 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 17:45:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
		return (len);
	}
	return (0);
}

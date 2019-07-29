/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:27:22 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 03:52:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static char			*ft_static(char *tmp, char *lf_ov)
{
	char			*leak;

	leak = ft_strjoin(lf_ov, tmp);
	free(tmp);
	ft_strdel(&lf_ov);
	return (leak);
}

static char			*ft_find_line(char *tmp)
{
	int				len_n;
	char			*line;
	static char		*lf_ov;

	if (lf_ov)
		tmp = ft_static(tmp, lf_ov);
	if (!(*tmp))
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	len_n = ft_strcspn(tmp, "\n");
	line = ft_strnew(len_n);
	line = ft_strncpy(line, tmp, len_n);
	if (len_n < (int)ft_strlen(tmp) && tmp != NULL)
		lf_ov = ft_strsub(tmp, len_n + 1, ft_strlen(ft_strchr(tmp, '\n')));
	ft_strdel(&tmp);
	return (line);
}

static int			ft_return(char *line, int ret)
{
	if (ret == -1)
	{
		free(&line);
		return (-1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			*leak;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, buff, 0) == -1)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		leak = *line;
		*line = ft_strjoin(*line, buff);
		free(leak);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	ft_return(*line, ret);
	*line = ft_find_line(*line);
	if (!(*line))
		return (0);
	return (1);
}

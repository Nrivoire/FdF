/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 15:00:34 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 17:13:47 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 128

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

int				get_next_line(const int fd, char **line);

#endif

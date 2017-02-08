/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:34:43 by rromero           #+#    #+#             */
/*   Updated: 2017/01/31 23:40:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

# include "libft.h"

typedef struct	s_file
{
	int			fd;
	short		ret;
	long long	b_rd;
	char		*tmp;
	char		*line;
	long long	l_len;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif

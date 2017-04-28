/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:49:41 by rromero           #+#    #+#             */
/*   Updated: 2017/01/31 23:41:53 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define
# define NULL_S "(null)"

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_agv //data in list
{
	size_t		vnum;
	char		type;
	size_t		size;
	int			width;
	int			prec;
	int			length;
	short		base;
	char		*printf_str;
}				f_agv;

/* ft_printf.c */
int				ft_printf(const char *s, ...);
int				printf_fd(const int fd, const char *s, ...);

/* get_var.c */
void			get_var(const char *format, f_agv *av, va_list av_lst);

/* read_var.c */
void			manage_flags(const char *format, f_agv *av);
void			manage_width(const char *format, f_agv *av);
void			manage_prec(const char *format, f_agv *av);
void			length_modifier(const char *format, f_agv *av);

/* print_var.c */
size_t			print_var(f_agv *av, const int fd);

/* helpers.c */
int				isSpecifier(char c);

#endif

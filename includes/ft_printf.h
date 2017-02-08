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

# include <stdarg.h>
# include "get_next_line.h"

typedef struct	s_format
{
	void		*data; //stack data
	char		*f_str; //format string (%-5.0f)
	char		*f_type; //ptr to f_str data type
}				t_avf;

typedef struct	s_param //data in list
{
	size_t		av_n; //current var #
	t_avf		*av_f; //format struct
	char		*av; //converted string
}				t_param;

int				ft_printf(const char *format, ...);

#endif

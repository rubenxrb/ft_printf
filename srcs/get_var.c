/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*avtostr(f_agv *av, va_list av_lst)
{
	char *str;

	str = 0;
	(void)av;
	(void)av_lst;
	return str;
}

static char	*get_format(const char *_format)
{
	char	*format;
	char	*p;
	size_t	size;

	printf("_format is: [%c]\n", *_format);
	size = ((p = (char *)_format) ? 1 : 0);
	while (!(isSpecifier(*p++)))
		size++;
	format = ft_strnew(size);
	return (ft_strncpy(format, _format, size));
}
static void	default_format(f_agv *av)
{
	f_agv	var;

	var = *av;
	var.vnum = 0;
	var.type = 0;
	var.size = 0;
	var.width = 0;
	var.prec = -1;
	var.length = 0;
	var.base = 0;
	var.printf_str = 0;
}

void get_var(const char *_format, f_agv *av, va_list av_lst)
{
	char	*format;

	format = 0;
	if ((format = get_format(++_format)))
	{
		printf("format (get_var); [%s]\n", format);
		default_format(av);
		manage_flags(format, av);
		manage_width(format, av);
		manage_prec(format, av);
		length_modifier(format, av);
		av->printf_str = avtostr(av, av_lst);
		free(format);
	}
}

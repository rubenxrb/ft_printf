/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:33:36 by rromero           #+#    #+#             */
/*   Updated: 2017/02/16 21:33:37 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			set_flags(t_agv *ret, const char *fmt)
{
	char	*tmp;
	size_t	size;

	size = 0;
	tmp = (char *)fmt;
	ret->flgs = 0;
	while (*tmp == '-' || *tmp == '0' || *tmp == '+' || *tmp == '#' ||
			*tmp == ' ' || *tmp == '$')
	{
		tmp++;
		size++;
	}
	if (size)
	{

		ret->flgs = ft_strnew(size);
		ret->flgs = ft_strncpy(ret->flgs, fmt, size);
	}
	return (size);
}

size_t			set_minwidth(t_agv *ret, const char *fmt)
{
	ret->width = 0;
	if (*fmt == '*')
		ret->width = -1;
	else if (ft_isdigit(*fmt))
		ret->width = ft_atoi(fmt);
	return (ft_numlen(ret->width, 10));
}

size_t			set_prec(t_agv *ret, const char *fmt)
{
	if (*(fmt + 1) == '*')
		ret->prec = -1;
	else if (ft_isdigit(*(fmt + 1)))
		ret->prec = ft_atoi(fmt + 1);
	return (ft_numlen(ret->prec, 10));
}


size_t			set_lmod(t_agv *ret, const char *fmt)
{
	char	*tmp;

	tmp = (char *)fmt;
	if (*tmp == *(tmp + 1))
	{
		if (*tmp == 'l')
			ret->l_mod = ft_strdup("ll");
		else if (*tmp == 'h')
			ret->l_mod = ft_strdup("hh");
		return (2);
	}
	ret->l_mod = ft_strnew(1);
	ret->l_mod[0] = *tmp;
	return (1);
}

size_t		set_base(const char type)
{
	if (ft_isletter(type, 'o'))
		return (8);
	else if (ft_isletter(type, 'x'))
		return (16);
	else if ((ft_isletter(type, 'd') || (type == 'i') || (type == 'n') ||
		(type == 'u')))
		return (10);
	return (0);
}

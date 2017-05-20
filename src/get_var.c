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

char	*get_format(const char *_format)
{
	char	*format;
	char	*p;
	size_t	size;

	size = ((p = (char *)_format) ? 1 : 0);
	while (!(isSpecifier(*p)) && (!(isModif(*p) && ft_isupper(*p))))
	{
		p++;
		size++;
	}
	format = ft_strnew(size);
	format = ft_strncpy(format, _format, size);
	return (format);
}

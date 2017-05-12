/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:16:18 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:16:19 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	wchar_len(wchar_t ch)
{
	if (ch < 0x80)
		return (1);
	else if (ch < 0x800)
		return (2);
	else if (ch < 0x10000)
		return (3);
	else if (ch < 0x110000)
		return (4);
	return (0);
}

size_t	wcharput(const wchar_t ch)
{
	wchar_t	c;

	(void)uctoutf8((char *)&c, ch);
	if (ch < 0x80)
		write(1, &c, 1);
	else if (ch < 0x800)
		write(1, &c, 2);
	else if (ch < 0x10000)
		write(1, &c, 3);
	else if (ch < 0x110000)
		write(1, &c, 4);
	return (wchar_len(ch));
}

size_t	wstrput(wchar_t const *s)
{
	size_t	len;

	len = 0;
	while (s)
		len += wcharput(*s++);
	return (len);
}

size_t	wstrlen(const wchar_t *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s)
			len += wchar_len(*s++);
	return (0);
}

wchar_t	*wstrnew(size_t len)
{
	wchar_t	*s;

	s = ft_memalloc((sizeof(wchar_t) * len) + sizeof(wchar_t));
	if (!s)
		return (0);
	return (s);
}

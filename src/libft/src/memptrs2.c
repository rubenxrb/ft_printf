/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memptrs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:11:23 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:11:26 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // memcpy, memccpy, memmove, memchr & memrchr

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)src;
	p2 = (unsigned char*)dst;
	if (n > 0)
		while (n--)
			*p2++ = *p1++;
	return (dst);
}

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	if (n > 0)
		while (n--)
			if ((*p2++ = *p1++) == (unsigned char)c)
				return (p2);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	if (p1 == p2)
		return (p2);
	if (p1 < p2)
	{
		p1 = p1 + len - 1;
		p2 = p2 + len - 1;
		while (len--)
			*p1-- = *p2--;
	}
	else
		while (len--)
			*p1++ = *p2++;
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!n)
		return (0);
	p = (unsigned char *)s;
	while (n--)
		if (*p++ == (unsigned char)c)
			return (p);
	return (0);
}

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!n)
		return (0);
	p = (unsigned char *)s + n;
	while (n--)
		if (*--p == (unsigned char)c)
			return (p);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:51:53 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:51:54 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strlen, strcpy, strncpy, strnew & strdup

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *t;

	t = dst;
	while ((len--) && (*src))
		*t++ = *src++;
	len++;
	while (len--)
		*t++ = '\0';
	return (dst);
}

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = ft_memalloc(size + 1)))
		return (0);
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = ft_strnew(ft_strlen(s1));
	if (!p)
		return (0);
	p = ft_strcpy(p, s1);
	return (p);
}

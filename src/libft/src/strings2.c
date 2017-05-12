/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:00:28 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:00:29 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strcat, strncat, strlcat, strchr & strrchr

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int			len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	while ((i < n) && (s2[i]))
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = 0;
	return (s1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (size < dlen)
		return (slen + size);
	while ((dlen + i + 1) < size && (src[i]))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				return ((char *)&s[i]);
			i++;
		}
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (ft_strlen(s));
	if (s[i--] == c)
		return ((char *)&s[++i]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

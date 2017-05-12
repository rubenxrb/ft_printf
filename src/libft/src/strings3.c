/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:00:49 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:00:50 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strstr, strnstr, strcmp, strncmp & strrev

char	*ft_strstr(const char *big, const char *little)
{
	int		e;

	e = 0;
	if (!*little)
		return ((char *)big);
	while (big[e])
		if (ft_strnequ(&big[e++], little, ft_strlen(little)))
			return ((char *)&big[--e]);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	length;

	if (!*little)
		return ((char *)big);
	length = ft_strlen(little);
	while (*big && len-- >= length)
	{
		if (*big == *little && !ft_memcmp(big, little, length))
			return ((char *)big);
		big++;
	}
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (p1[i] || p2[i]))
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

char	*ft_strrev(const char *s)
{
	char	*ps;
	char	*pf;
	char	tmp;

	if (!s || !*s)
		return ((char *)s);
	ps = (char *)s;
	pf = ps + (ft_strlen(s) - 1);
	while (pf > ps)
	{
		tmp = *ps;
		*ps++ = *pf;
		*pf-- = tmp;
	}
	return ((char *)s);
}

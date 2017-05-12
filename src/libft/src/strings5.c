/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:01:03 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:01:04 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strmapi, strequ, strnequ, strsub & strjoin

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	if (!s)
		return (0);
	p = ft_strnew(ft_strlen(s));
	i = 0;
	if (!p)
		return (0);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (!s1 || !s2)
		return (1);
	i = ft_strcmp(s1, s2);
	return (!i);
}

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	char	*p;

	if (!s || !(p = ft_strnew(len)))
		return (0);
	ft_strncpy(p, &s[start], len);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	if (!s1 || !s2)
		return (0);
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!s3)
		return (0);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}

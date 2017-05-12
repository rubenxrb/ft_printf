/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:01:09 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:01:11 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strtrim, strsplit, <wordcount>, <nextword> & strinsrt

char		*ft_strtrim(char const *s)
{
	char *p;

	if (!s)
		return (0);
	while (ft_isblank(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	p = (char *)(s + (ft_strlen(s) - 1));
	while (ft_isblank(*p))
		p--;
	return (ft_strsub(s, 0, (p - s + 1)));
}

static int	wordcount(char const *s, char c)
{
	int		t;

	t = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (*(s + 1) == c || !(*(s + 1)))
				t++;
			s++;
		}
	}
	return (t);
}

static char	*nextword(const char *s, char c, size_t *ele)
{
	size_t		i;

	i = 0;
	while (s[*ele] == c)
		*ele += 1;
	i = *ele;
	while (s[*ele])
	{
		if (s[*ele] == c)
			break ;
		*ele += 1;
	}
	return (ft_strsub(s, i, *ele - i));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		words;
	size_t	element;

	index = 0;
	element = 0;
	words = wordcount(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	while (index < words)
		str[index++] = nextword(s, c, &element);
	str[index] = 0;
	return (str);
}

char		*ft_strinsrt(const char *dst, size_t n, const char *src)
{
	char	*str;

	if (!dst || (n > ft_strlen(dst)))
		return (0);
	str = ft_strnew(ft_strlen(dst) + ft_strlen(src));
	(void)ft_strncpy(str, dst, n);
	(void)ft_strcpy(str + n, src);
	return (ft_strcat(str, dst + n));
}

#include "libft.h"

char	*strtolower(char *str)
{
	char	*p;

	p = str;
	while (*p)
	{
		*p = ft_tolower(*p);
		p++;
	}
	return (str);
}

char	*printfstrdup(const char *s1)
{
	char	*p;

	if (!s1)
		return (ft_strdup("(null)"));
	p = ft_strnew(ft_strlen(s1));
	if (!p)
		return (0);
	p = ft_strcpy(p, s1);
	return (p);
}

char	*ft_strnchr(const char *s, int c, size_t len)
{
	int		i;

	i = 0;
	if (s && len)
	{
		while (s[i] && len--)
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

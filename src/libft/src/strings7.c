#include "libft.h"

size_t	count_words(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		if (ft_isblank(*str))
			str++;
		else
		{
			if (ft_isblank(*(str + 1)) || !(*(str + 1)))
				count++;
			str++;
		}
	}
	return (count);
}

char	*get_next_word(const char *s, char **word)
{
	char	*t;

	if (!s)
		return (0);
	while (*s)
	{
		if (ft_isblank(*s))
			s++;
		else
		{
			t = (char *)s;
			while (*t && !ft_isblank(*t))
				t++;
			*word = ft_strsub(s, 0, t - s);
			return (t);
		}
	}
	return (0);
}

char	**split_blnk(const char *str)
{
	char	**tab;
	char	*p;
	size_t	w;
	size_t	i;

	w = count_words(str);
	tab = ft_memalloc((sizeof(char *) * w) + 1);
	p = (char *)str;
	i = 0;
	while (*p && (i < w))
		p = get_next_word(p, &tab[i++]);
	tab[i] = 0;
	return (tab);
}

void	free_tab(char **ap)
{
	if (!ap)
		return ;
	while (*ap)
		ft_strdel(&*ap++);
}

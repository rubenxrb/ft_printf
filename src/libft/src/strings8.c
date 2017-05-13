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

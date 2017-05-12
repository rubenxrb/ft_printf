#include "libft.h"

wchar_t	*wstrdup(const wchar_t *src)
{
	wchar_t	*new;
	size_t	len;

	len = wstrlen(src);
	new = wstrnew(len);
	if (!new)
		return (0);
	new = ft_memcpy(new, src, sizeof(wchar_t) * len);
	return (new);
}

#include "libft.h"

wchar_t	*wstrdup(const wchar_t *src)
{
	wchar_t	*new;
	size_t	len;

	ft_putendl("SEG");
	len = wstrlen(src);
	new = wstrnew(len);
	ft_putendl("SEG2");
	if (!new)
		return (0);
	new = ft_memcpy(new, src, sizeof(wchar_t) * len);
	return (new);
}

wchar_t	*wchardup(const wchar_t src)
{
	wchar_t	*new;

	new = ft_memalloc(sizeof(wchar_t));
	if (!new)
		return (0);
	return (ft_memcpy(new, &src, sizeof(wchar_t)));
}

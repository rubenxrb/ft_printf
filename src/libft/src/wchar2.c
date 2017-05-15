#include "libft.h"
#include <unistd.h>

wchar_t	*wstrdup(const wchar_t *src)
{
	wchar_t	*new;
	size_t	len;

	len = wstrlen(src);
	new = wstrnew(len * sizeof(wchar_t));
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

size_t	wcharput_fd(const wchar_t ch, const int fd)
{
	wchar_t	c;

	uctoutf8((char *)&c, ch);
	if (ch < 0x80)
		write(fd, &c, 1);
	else if (ch < 0x800)
		write(fd, &c, 2);
	else if (ch < 0x10000)
		write(fd, &c, 3);
	else if (ch < 0x110000)
		write(fd, &c, 4);
	return (wchar_len(ch));
}

size_t	wstrput_fd(const wchar_t *src, const int fd, size_t len)
{
	size_t	r;

	r = 0;
	while (len--)
	{
		r++;
		wcharput_fd(*src++, fd);
	}
	return (r);
}

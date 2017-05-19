#include "libft.h"

void	append_char(t_array **curr, size_t times, char ch)
{
	char	*tmp;

	tmp = ft_strdup((*curr)->data);
	*curr = array_resize(*curr, (*curr)->len + times);
	(*curr)->bytes = (*curr)->len - 1;
	ft_memset((*curr)->data, ch, times);
	ft_memcpy((*curr)->data + times, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
}

void	cat_char(t_array **curr, size_t times, int ch)
{
	size_t	old;

	old = (*curr)->bytes;
	*curr = array_resize(*curr, (*curr)->len + times);
	(*curr)->bytes = (*curr)->len - 1;
	ft_memset((*curr)->data + old, ch, times);
}

void	append_atchar(t_array **curr, size_t at, size_t times, char ch)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strnew(times);
	ft_memset(tmp, ch, times);
	ret = ft_strinsrt((*curr)->data, at, tmp);
	ft_strdel(&tmp);
	ft_memdel(&(*curr)->data);
	(*curr)->data = ret;
	(*curr)->bytes = ft_strlen(ret);
	(*curr)->len = (*curr)->bytes + 1;
}

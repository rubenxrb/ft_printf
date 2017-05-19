#include "ft_printf.h"

static t_array *make_date(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (array_new(sizeof(char), 1));
}

static t_array *make_printable(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (array_new(sizeof(char), 1));
}

static t_array *make_ptr(t_agv *fmt, va_list *ap)
{
	t_array	tmp;

	tmp.data = ft_hextoa(va_arg(*ap, long), fmt->prec);
	tmp.data = strtolower(tmp.data);
	tmp.d_size = 1;
	tmp.bytes = ft_strlen(tmp.data);
	tmp.len = tmp.bytes + 1;
	return (array_clone(&tmp));
}

t_array	*make_utils(t_agv *fmt, char type, va_list *ap)
{
	t_array	*ret;

	ret = 0;
	if (type == '%')
	{
		ret = array_new(1, 2);
		ft_memcpy(ret->data, &type, 1);
	}
	else if (type == 'k')
		ret = make_cstr(fmt, ap);
	else if (type == 'p')
		ret = make_ptr(fmt, ap);
	else if (type == '~')
		ret = make_date(fmt, ap);
	else if (type == 'r')
		ret = make_printable(fmt, ap);
	return ret;
}

/*	appends 0x or 0X to type, append 0 to octal if len > 1 || oc != '0'*/
void	uint_prefix(t_array **hex, char type)
{
	char	*tmp;
	size_t	old;

	tmp = 0;
	if (ft_isletter(type, 'x'))
	{
		old = (*hex)->bytes;
		tmp = ft_strdup((*hex)->data);
		*hex = array_resize(*hex, (*hex)->len + 2);
		(*hex)->bytes = (*hex)->len - 1;
		ft_memcpy((*hex)->data, ft_isupper(type) ? "0X" : "0x", 2);
		ft_memcpy((*hex)->data + 2, tmp, old);
	}
	else if (ft_atoi((*hex)->data))
	{
		old = (*hex)->bytes;
		tmp = ft_strdup((*hex)->data);
		*hex = array_resize(*hex, (*hex)->len + 1);
		(*hex)->bytes = (*hex)->len - 1;
		ft_memcpy((*hex)->data, "0", 1);
		ft_memcpy((*hex)->data + 1, tmp, old);
	}
	ft_strdel(&tmp);
}

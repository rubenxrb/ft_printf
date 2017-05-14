#include "ft_printf.h"

t_array	*make_utils(t_agv *fmt, char type, va_list *ap)
{
	t_array	*ret;
	(void)fmt;
	(void)type;
	(void)ap;
	ret = array_new(sizeof(char), 2);
	if (type == '%')
		ft_memcpy(ret->data, &type, 1);
	return ret;
}

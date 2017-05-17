#include "ft_printf.h"

t_array	*make_utils(t_agv *fmt, char type, va_list *ap)
{
	t_array	*ret;

	if (type == '%')
	{
		ret = array_new(1, 2);
		ft_memcpy(ret->data, &type, 1);
	}
	else if (type == 'k')
	{
		ret = make_str(fmt, ap);
		printf("k : '%s'\n", (char *)ret->data);
		printf("base : '%zu'\n", fmt->base);
	}
	return ret;
}

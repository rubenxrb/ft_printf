#include "ft_printf.h"

t_array	*make_utils(t_agv *fmt, char type, va_list *ap)
{
	t_array	*ret;
	t_array	tmp;

	ret = 0;
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
	else if (type == 'p')
	{
		tmp.data = ft_hextoa(va_arg(*ap, long), fmt->prec);
		tmp.data = strtolower(tmp.data);
		tmp.d_size = 1;
		tmp.bytes = ft_strlen(tmp.data);
		tmp.len = tmp.bytes + 1;
		return (array_clone(&tmp));
	}
	return ret;
}

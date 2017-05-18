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

/*	appends 0x or 0X to type, append 0 to octal if len > 1 || oc != '0'*/
void	uint_prefix(t_array **hex, char type)
{
	if (ft_isletter(type, 'x'))
	{
		*hex = array_resize(*hex, (*hex)->len + 2);
		ft_memmove((*hex)->data + 2, (*hex)->data, (*hex)->bytes);
		ft_memcpy((*hex)->data, ft_isupper(type) ? "0X" : "0x", 2);
	}
	else if ((*hex)->bytes > 1)
	{
		*hex = array_resize(*hex, (*hex)->len + 1);
		ft_memmove((*hex)->data + 1, (*hex)->data, (*hex)->bytes);
		ft_memcpy((*hex)->data, "0", 1);
	}
}

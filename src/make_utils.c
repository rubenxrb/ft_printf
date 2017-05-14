#include "ft_printf.h"

t_array	*make_utils(t_agv *fmt, char type, va_list *ap)
{
	(void)fmt;
	(void)type;
	(void)ap;
	return array_new(sizeof(char), 1);
}

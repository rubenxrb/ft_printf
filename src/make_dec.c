#include "ft_printf.h"

t_array		*make_decimal(t_agv *fmt, char type, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)type;
	(void)ap;
	(void)caps;
	return array_new(sizeof(double), 1);
}

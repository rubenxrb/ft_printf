#include "ft_printf.h"

t_array		*make_hex(t_agv *fmt, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)caps;
	(void)ap;
	return array_new(sizeof(char), 1);
}

t_array		*make_fhex(t_agv *fmt, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)caps;
	(void)ap;
	return array_new(sizeof(char), 1);
}

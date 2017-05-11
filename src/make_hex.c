#include "ft_printf.h"

char	*make_hex(t_agv *fmt, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)caps;
	(void)ap;
	return ft_strdup(&fmt->type);
}

char	*make_fhex(t_agv *fmt, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)caps;
	(void)ap;
	return ft_strdup(&fmt->type);
}

#include "ft_printf.h"

char	*make_decimal(t_agv *fmt, char type, va_list *ap)
{
	(void)fmt;
	(void)type;
	(void)ap;
	return ft_strdup(&fmt->type);
}

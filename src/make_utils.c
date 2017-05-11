#include "ft_printf.h"

char	*make_ptr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

char	*make_npstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

#include "ft_printf.h"

void	*make_str(t_agv *fmt, va_list *ap)
{
	char	*ret;
	//size_t	len;

	ret = va_arg(*ap, char *);
	(void)fmt;
	(void)ap;
	return ft_strdup(ret);
}

void	*make_wstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

void	*make_cstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}


void	*make_cwstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

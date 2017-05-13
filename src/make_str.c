#include "ft_printf.h"

t_array	*make_str(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (0);
}

/*
char	*str;
char	*agv;
size_t	spc;
int		size;

agv = va_arg(*ap, char *);
size = ft_strlen(agv);
if (!fmt->prec || (fmt->prec > size))
	fmt->prec = size;
spc = fmt->width > fmt->prec ? fmt->width - fmt->prec : 0;
str = ft_strnew(spc + fmt->prec);
if (spc)
	str = ft_memset(str, ' ', spc + fmt->prec);
if (fmt->flgs && fmt->flgs[0] == '-')
	ft_strncpy(str, agv, fmt->prec);
else
	ft_strncpy(str + spc, agv, fmt->prec);
return (str);
*/


t_array	*make_wstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return 0;
}

t_array	*make_cstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return 0;
}


t_array	*make_cwstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return 0;
}

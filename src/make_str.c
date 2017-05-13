#include "ft_printf.h"

t_array	*make_str(t_agv *fmt, va_list *ap)
{
	t_array	*str;
	char	*agv;
	int		len;
	char	sp;

	agv = ft_strdup(va_arg(*ap, char *));
	sp = fmt->flgs ? fmt->flgs[0] : 0;
	if (fmt->prec <= (int)ft_strlen(agv))
		*(agv + fmt->prec) = 0;
	len = ft_strlen(agv);
	str = array_new(sizeof(char), (fmt->width > fmt->prec ? fmt->width : len) + 1);
	str->bytes = str->len - 1;
	ft_strcpy(str->data, agv);
	if (fmt->width > fmt->prec)
	{
		ft_memset(str->data, ((sp == '0') ? sp : ' '), str->bytes);
		if (sp == '-')
			ft_strncpy(str->data, agv, ft_strlen(agv));
		else
			ft_strncpy(str->data + (str->bytes - fmt->prec), agv, ft_strlen(agv));
	}
	ft_strdel(&agv);
	return (str);
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

if prec

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

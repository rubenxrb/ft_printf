#include "ft_printf.h"

t_array	*make_str(t_agv *fmt, va_list *ap)
{
	t_array	*str;
	char	*agv;
	int		len;
	char	*sp;

	agv = printfstrdup(va_arg(*ap, char *));
	sp = fmt->flgs ? fmt->flgs : 0;
	if ((sp) && *sp == '-')
		sp++;
	if (fmt->prec <= (int)ft_strlen(agv) && fmt->prec > 0)
		*(agv + fmt->prec) = 0;
	len = ft_strlen(agv);
	str = array_new(1, (fmt->width > fmt->prec ? fmt->width : len) + 1);
	str->bytes = str->len - 1;
	ft_strcpy(str->data, agv);
	if (fmt->width > fmt->prec)
	{
		ft_memset(str->data, sp && *sp == '0' ? *sp : ' ', str->bytes);
		if (ft_strchr(fmt->flgs, '-'))
			ft_strncpy(str->data, agv, len);	//check if ' '|'0' -> preappend to the right
		else
			ft_strncpy(str->data + (str->bytes - fmt->prec), agv, len);
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
	t_array	*str;
	wchar_t	*agv;
	size_t	len;

	(void)fmt;
	agv = wstrdup(va_arg(*ap, wchar_t *));
	len = wstrlen(agv);
	str = array_new(sizeof(wchar_t), len);
	//printf(" '%zu' '%zu' '%zu'\n", str->len, str->d_size, str->bytes);
	ft_memcpy(str->data, agv, str->bytes);
//	printf("[%S]", (wchar_t *)str->data);
	ft_memdel((void **)&agv);
	return (str);
}

t_array	*make_cstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return array_new(sizeof(char), 1);
}


t_array	*make_cwstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return array_new(sizeof(wchar_t), 1);
}

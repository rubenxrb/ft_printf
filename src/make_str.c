#include "ft_printf.h"

t_array	*make_str(t_agv *fmt, va_list *ap)
{
	t_array	*str;
	t_array	agv;
	size_t	spc = 0;

	printf("[x] prc: '%d' width: '%d' spc: '%zu'\n", fmt->prec, fmt->width, spc);
	agv.data = va_arg(*ap, char *);
	agv.len = ft_strlen(agv.data);
	if (!fmt->prec || fmt->prec > (int)agv.len)
		fmt->width = agv.len;
	spc = agv.len - fmt->prec;
	str = array_new(sizeof(char), (spc + fmt->prec) + 1);
	str->bytes = str->len - 1;
	printf("prc: '%d' width: '%d' spc: '%zu'\n", fmt->prec, fmt->width, spc);
	printf("arr: dsize '%zu' len '%zu' bytes '%zu'\n", str->d_size, str->len, str->bytes);
	if (spc)
		ft_memset(str->data, ' ', str->bytes);
	if (fmt->flgs && fmt->flgs[0] == '-')
		ft_strncpy(str->data, agv.data, fmt->prec);
	else
		ft_strncpy(str->data + spc, agv.data, fmt->prec);
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

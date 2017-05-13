#include "ft_printf.h"
#include <inttypes.h>



static void	format_integer(t_agv *fmt, t_array *ret, char t, t_byte sig)//free old integer
{
	char	*ch;
	char	sp;

	sp = fmt->flgs ? fmt->flgs[0] : 0;
	ch = ft_strnew((fmt->width > fmt->prec) ? (size_t)fmt->width : ret->len);
//	printf("fmt:w '%d' fmt:p '%d'\n", fmt->width, fmt->prec);
	//printf("arr:l '%zu' arr:b '%zu' arr: '%s'\n", ret->len, ret->bytes, (char *)ret->data);
	(void)ret;
	(void)fmt;
	(void)sig;
	(void)t;
	(void)ch;
	(void)sp;
}

/*
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
		ft_strncpy(str->data, agv, ft_strlen(agv));	//check if ' '|'0' -> preappend to the right
	else
		ft_strncpy(str->data + (str->bytes - fmt->prec), agv, ft_strlen(agv));
}
ft_strdel(&agv);
return (str);

*/

static void	*make_sint(t_agv *fmt, char *lmod, va_list *ap)
{
	t_array	tmp;
	char	hh;
	short	h;

	tmp.d_size = 1;
	if (!lmod)
		tmp.data = ft_itoa_base(va_arg(*ap, int), fmt->base);
	else if (ft_strequ(lmod, "hh") && (hh = va_arg(*ap, int)))
		tmp.data = ft_itoa_base(hh, fmt->base);
	else if (ft_strequ(lmod, "ll"))
		tmp.data = ft_lltoa_base(va_arg(*ap, long long), fmt->base);
	else if (*lmod == 'h' && (h = va_arg(*ap, int)))
		tmp.data = ft_itoa_base(h, fmt->base);
	else if (*lmod == 'l')
		tmp.data = ft_itoa_base(va_arg(*ap, long), fmt->base);
	else if (*lmod == 'j')
		tmp.data = ft_itoa_base(va_arg(*ap, intmax_t), fmt->base);
	else if (*lmod == 'z')
		tmp.data = ft_itoa_base(va_arg(*ap, ssize_t), fmt->base);
	else if (*lmod == 't')
		tmp.data = ft_itoa_base(va_arg(*ap, ptrdiff_t), fmt->base);
	tmp.len = (ft_strlen(tmp.data) + 1);
	tmp.bytes = tmp.len - 1;
	return (array_clone(&tmp));
}

t_array	*make_signed(t_agv *fmt, char type, va_list *ap)
{
	t_array	*ret;
	char	*lmod;
	t_byte	wc;
	int		ch;

	ret = 0;
	lmod = fmt->l_mod ? fmt->l_mod : 0;
	if (ft_isletter(type, 'c'))
	{
		wc = (lmod && lmod[0] == 'l') || ft_isupper(type);
		ret = array_new(wc ? sizeof(wint_t) : sizeof(int), 1);
		if (wc && (ch = va_arg(*ap, wint_t)))
			ft_memcpy(ret->data, &ch, sizeof(wint_t));
		else if ((ch = va_arg(*ap, int)))
			ft_memcpy(ret->data, &ch, sizeof(int));
	}
	else if (ft_isletter(type, 'd') || type == 'i' || type == 'n')
	{
		fmt->prec = fmt->prec ? fmt->prec : 1;
		ret = make_sint(fmt, lmod, ap);
	}
	if (type != 'n' && ret)
		format_integer(fmt, ret, type, 1);
	return (ret);
}

t_array	*make_uint(t_agv *fmt, char *lmod, va_list *ap)
{
	t_array			tmp;
	unsigned char	hh;
	unsigned short	h;

	tmp.d_size = 1;
	fmt->prec = fmt->prec ? fmt->prec : 1;
	if (!lmod)
		tmp.data = ft_itoa_base(va_arg(*ap, unsigned int), fmt->base);
	else if (ft_strequ(lmod, "hh") && (hh = va_arg(*ap, unsigned int)))
		tmp.data = ft_itoa_base(hh, fmt->base);						//char
	else if (ft_strequ(lmod, "ll"))								//longlong
		tmp.data =ft_lltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (*lmod == 'h' && (h = va_arg(*ap, unsigned int)))			//short
		tmp.data =ft_itoa_base(h, fmt->base);
	else if (*lmod == 'l')										//long
		tmp.data =ft_itoa_base(va_arg(*ap, unsigned long), fmt->base);
	else if (*lmod == 'j')										//intmax_t
		tmp.data =ft_itoa_base(va_arg(*ap, uintmax_t), fmt->base);
	else if (*lmod == 'z')										//signed size_t
		tmp.data = ft_itoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 't')										//ptrdiff_t
		tmp.data = ft_itoa_base(va_arg(*ap, unsigned long long), fmt->base);
	tmp.len = (ft_strlen(tmp.data) + 1);
	tmp.bytes = tmp.len - 1;
	return (array_clone(&tmp));
}

/*

STRING
s[l] = char * , wchar *

INTEGERS: [hh, h, l, ll, j, z, t]		<if 'l' used in c, convert to uns char>
c[l], d, i, n = signed numbers			<note: c can just have 'l' lenmod>
o-O, x-X, u = unsigned numbers

d,i,c = print '' if no chars to print
oO = print '0' if no chars to print
xX = print if (num != 0) append "0x || 0X", print '' if no chars to print


FLOATS: [l,L]
f-F, e-E, a-A, g-G = floating point numbers
prec default: 6
g, G = max # of number as chars

POINTER: (none)
p = void *

'yyyy'-'MM'-'dd'-'T'-'HH':'mm':'ss'.

type var = va_arg(lst, type);

*/

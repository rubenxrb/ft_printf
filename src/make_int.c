#include "ft_printf.h"
#include <inttypes.h>



static void	*format_integer(t_agv *fmt, char type, char *num, t_byte sig)//free old integer
{
	(void)fmt;
	(void)type;
	(void)sig;
//	ft_putendl("MAKING INT");
	return (num);
}

static void	*make_sint(t_agv *fmt, char *lmod, va_list *ap)
{
	char	hh;
	short	h;
	char	*n;

	n = 0;
	if (!lmod)
		n = ft_itoa_base(va_arg(*ap, int), fmt->base);
	else if (ft_strequ(lmod, "hh") && (hh = va_arg(*ap, int)))
		n = ft_itoa_base(hh, fmt->base);
	else if (ft_strequ(lmod, "ll"))
		n = ft_lltoa_base(va_arg(*ap, long long), fmt->base);
	else if (*lmod == 'h' && (h = va_arg(*ap, int)))
		n = ft_itoa_base(h, fmt->base);
	else if (*lmod == 'l')
		n = ft_itoa_base(va_arg(*ap, long), fmt->base);
	else if (*lmod == 'j')
		n = ft_itoa_base(va_arg(*ap, intmax_t), fmt->base);
	else if (*lmod == 'z')
		n = ft_itoa_base(va_arg(*ap, ssize_t), fmt->base);
	else if (*lmod == 't')
		n = ft_itoa_base(va_arg(*ap, ptrdiff_t), fmt->base);
	return (n);
}

t_array	*make_signed(t_agv *fmt, char type, va_list *ap)
{
	char	*lmod;
	void	*ret;
	//int		*n;
//	int *p;

	//ft_putendl("MAKING SIGNED");
	ret = 0;
	lmod = fmt->l_mod ? fmt->l_mod : 0;
	if (type == 'c')
		if (lmod && lmod[0] == 'l')
			ret = wchardup(va_arg(*ap, wint_t));
		else
			ret = ft_chardup(va_arg(*ap, int));
	else if (type == 'd' || type == 'i')
	{
		fmt->prec = fmt->prec ? fmt->prec : 1;
		ret = make_sint(fmt, lmod, ap);
	}
	else if (type == 'n')
		ret = va_arg(*ap, int *);
	if (type != 'n' && ret)
		ret = format_integer(fmt, type, ret, 1);
	ft_putendl("SIGNED MADE");
//	exit(1);
	return (ret);
}

static void	*make_uint(t_agv *fmt, char *lmod, va_list *ap)
{
	unsigned char	hh;
	unsigned short	h;
	char	*n;

	n = 0;
	if (!lmod)
		n = ft_itoa_base(va_arg(*ap, unsigned int), fmt->base);
	else if (ft_strequ(lmod, "hh") && (hh = va_arg(*ap, unsigned int)))
		n = ft_itoa_base(hh, fmt->base);						//char
	else if (ft_strequ(lmod, "ll"))								//longlong
		n = ft_lltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (*lmod == 'h' && (h = va_arg(*ap, unsigned int)))			//short
		n = ft_itoa_base(h, fmt->base);
	else if (*lmod == 'l')										//long
		n = ft_itoa_base(va_arg(*ap, unsigned long), fmt->base);
	else if (*lmod == 'j')										//intmax_t
		n = ft_itoa_base(va_arg(*ap, uintmax_t), fmt->base);
	else if (*lmod == 'z')										//signed size_t
		n = ft_itoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 't')										//ptrdiff_t
		n = ft_itoa_base(va_arg(*ap, unsigned long long), fmt->base);
	return (n);
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

t_array	*make_unsigned(t_agv *fmt, char type, va_list *ap)
{
	char	*lmod;
	void	*ret;
	//size_t	n;

	ret = 0;
//	ft_putendl("MAKE UNSIGNED");
	lmod = fmt->l_mod ? fmt->l_mod : 0;
	fmt->prec = fmt->prec ? fmt->prec : 1;
	ret = make_uint(fmt, lmod, ap);
	(void)type;
	return ret;
}

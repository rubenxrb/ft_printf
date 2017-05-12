#include "ft_printf.h"

/*

STRING
s[l] = char * , wchar *

INTEGERS: [hh, h, l, ll, j, z, t]		<if 'l' used in c, convert to uns char>
c[l], d, i, n = signed numbers			<note: c can just have 'l' lenmod>
o-O, x-X, u = unsigned numbers

FLOATS: [l,L]
f-F, e-E, a-A, g-G = floating point numbers
prec default: 6
g, G = max # of number as chars

POINTER: (none)
p = void *

'yyyy'-'MM'-'dd'-'T'-'HH':'mm':'ss'.

type var = va_arg(lst, type);

*/

static void	*make_sint(t_agv *fmt, char *lmod, va_list *ap)
{
	(void)fmt;
	(void)lmod;
	(void)ap;
	return (0);
}

void	*make_signed(t_agv *fmt, char type, va_list *ap)
{
	char	*lmod;
	void	*ret;
	int		*n;

	ret = 0;
	lmod = fmt->l_mod ? fmt->l_mod : 0;
	if (type == 'c')
	{
		if (lmod && lmod[0] == 'l')
			return (wchardup(va_arg(*ap, wint_t)));
		else
			return (ft_chardup(va_arg(*ap, int)));
	}
	else if (type == 'd' || type == 'i')
		ret = make_sint(fmt, lmod, ap);
	else if (type == 'n')
	{
		n = va_arg(*ap, int *);
		ret = ft_memalloc(sizeof(int *));
		ret = ft_memcpy(ret, &n, sizeof(int *));
	}
	return (ret);
}

void	*make_unsigned(t_agv *fmt, char type, va_list *ap)
{
	(void)fmt;
	(void)type;
	(void)ap;
	return ft_strdup(&fmt->type);
}

#include "ft_printf.h"
#include <inttypes.h>

static void append_char(t_array **ret, int times, char ch)
{
	char	*tmp;

//	printf("appending '%c' '%d'times\n", ch, times);
	tmp = ft_strdup((*ret)->data);
	*ret = array_resize(*ret, (*ret)->len + times);
	(*ret)->bytes = (*ret)->len - 1;
	ft_memset((*ret)->data, ch, times);
	//printf("mem '%s' bytes'%zu'\n", (char *)(*ret)->data, (*ret)->bytes);
	ft_memcpy((*ret)->data + times, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
//	printf("mem '%s' bytes'%zu'\n", (char *)(*ret)->data, (*ret)->bytes);
}
/*
static void number_width(t_agv *fmt, t_array **ret, char *n, int sp)
{
	char	sign;
	char	*tmp;

	tmp = ft_strdup((*ret)->data);
	sign = ft_atoi(n) < 0 ? 1 : 0;
	printf("number width '%d'\n", sp);
	*ret = array_resize(*ret, (*ret)->len + sp);
	(*ret)->bytes = (*ret)->len - 1;
	//printf("mem '%s' bytes'%zu'\n", (char *)(*ret)->data, (*ret)->bytes);
	ft_memset((*ret)->data, ' ', (*ret)->bytes);
	if (fmt->flgs && fmt->flgs[0] == '-')
		ft_memcpy((*ret)->data + sign, tmp, ft_strlen(tmp));
	else
		ft_memcpy((*ret)->data + sp + sign, tmp, ft_strlen(tmp));
	//printf("mem '%s' bytes'%zu'\n", (char *)(*ret)->data, (*ret)->bytes);
	ft_strdel(&tmp);
}
*/

static void	format_integer(t_agv *fmt, t_array **ret)//free old integer
{
	char	*n;
	char	sp;
	int		len;
	char	sign;

	n = ft_strdup((*ret)->data);
	sign = (ft_atoi(n) < 0 || ft_strchr(fmt->flgs, '+')) ? 1 : 0;
	len = ft_strlen(n) - (ft_atoi(n) < 0 ? 1 : 0);
	if (ft_strchr(fmt->flgs, ' '))
		sp = ' ';
	else if (ft_strchr(fmt->flgs, '0'))
		sp = '0';
	if (fmt->prec > len)
		append_char(ret, fmt->prec - len, '0');
	//printf("width '%d' bytes'%zu'\n", fmt->width, (*ret)->bytes);
	if (fmt->width > (int)(*ret)->bytes)
		append_char(ret, fmt->width - (int)(*ret)->bytes, sp == '0' ? sp : ' ');
	else if (sp && ft_atoi((*ret)->data))
		append_char(ret, 1, ' ');
	if (sign)
		ft_memset((*ret)->data, ft_atoi(n) < 0 ? '-' : '+', 1);
	ft_strdel(&n);
}

/* manage adding 0 to str->data if needed as prec */
/* if width > len append min width */
	/* get value of spaces ' ' or '0' */
	/* if '-' flag is set append spaces to the left, else; to the right*/
/* if pl append '+' or '-' according to sign */

/* SIGNED INTEGERS */
static t_array	*make_sint(t_agv *fmt, char *lmod, va_list *ap)
{
	t_array	tmp;
	char	hh;
	short	h;

	tmp.d_size = 1;
	if (!lmod && !ft_isupper(fmt->type))
		tmp.data = ft_itoa_base(va_arg(*ap, int), fmt->base);
	else if (lmod && !ft_strcmp(lmod, "hh") && (hh = va_arg(*ap, int)))
		tmp.data = ft_itoa_base(hh, fmt->base);
	else if (lmod && !ft_strcmp(lmod, "ll"))
		tmp.data = ft_lltoa_base(va_arg(*ap, long long), fmt->base);
	else if ((lmod && *lmod == 'l') || ft_isupper(fmt->type))
		tmp.data = ft_lltoa_base(va_arg(*ap, long long), fmt->base);
	else if (*lmod == 'h' && (h = va_arg(*ap, int)))
		tmp.data = ft_itoa_base(h, fmt->base);
	else if (*lmod == 'j')
		tmp.data = ft_lltoa_base(va_arg(*ap, intmax_t), fmt->base);
	else if (*lmod == 'z')
		tmp.data = ft_lltoa_base(va_arg(*ap, ssize_t), fmt->base);
	else if (*lmod == 't')
		tmp.data = ft_lltoa_base(va_arg(*ap, ptrdiff_t), fmt->base);
//	printf("rip? tmp.data '%s'\n", (char *)tmp.data);
	tmp.len = (ft_strlen(tmp.data) + 1);
	tmp.bytes = tmp.len - 1;
	return (array_clone(&tmp));
}

static t_array	*make_nptr(va_list *ap)
{
	t_array	*nptr;
	int		*num;

	if (!(num = va_arg(*ap, int *)))
		return (0);
	nptr = ft_memalloc(sizeof(t_array));
	nptr->d_size = 0;
	nptr->len = 1;
	nptr->bytes = sizeof(int *);
	nptr->data = num;
	return (nptr);
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
		ch = va_arg(*ap, int);
		ret = array_new(wc ? sizeof(wchar_t) : sizeof(int), wc ? 2 : 1);
		ret->bytes = wc ? wchar_len(ch) : 1;
		ret->len = 1;
		ft_memcpy(ret->data, &ch, ret->bytes);
	}
	else if (ft_isletter(type, 'd') || type == 'i' || type == 'n')
	{
		fmt->prec = fmt->prec ? fmt->prec : 1;
		ret = (type  == 'n') ? make_nptr(ap) : make_sint(fmt, lmod, &*ap);
	}
	if (type != 'n' && ret && (ft_atoi(ret->data)))
		format_integer(fmt, &ret);	//check if integer needs to be formated, ex: 0
	return (ret);
}

/* UNSIGNED INTS */
t_array	*make_uint(t_agv *fmt, char *lmod, va_list *ap)
{
	t_array			tmp;

	tmp.d_size = 1;
	fmt->prec = fmt->prec ? fmt->prec : 1;
	if (!lmod && !ft_isupper(fmt->type))
		tmp.data = ft_uitoa_base(va_arg(*ap, size_t), fmt->base);
	else if (lmod && !ft_strcmp(lmod, "hh"))
		tmp.data = ft_uitoa_base(va_arg(*ap, size_t), fmt->base);					//char
	else if (lmod && !ft_strcmp(lmod, "ll"))								//longlong
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (ft_isupper(fmt->type) || *lmod == 'l')										//long
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (*lmod == 'h')			//short
		tmp.data = ft_uitoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 'j')										//intmax_t
		tmp.data = ft_ulltoa_base(va_arg(*ap, uintmax_t), fmt->base);
	else if (*lmod == 'z')										//signed size_t
		tmp.data = ft_ulltoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 't')										//ptrdiff_t
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
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

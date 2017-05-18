#include "ft_printf.h"
#include <inttypes.h>



static void	format_integer(t_agv *fmt, t_array **ret, char t, t_byte sig)//free old integer
{
	size_t	len;
	char	*nbrs;
	char	*fl;

	(void)t;
	(void)sig;
	//printf("flgs: '%s'\n", fmt->flgs);
	//printf("wid: '%d'\n", fmt->width);
//	printf("ret '%s' by'%zu' ln'%zu' ds'%zu'\n", (char *)(*ret)->data, (*ret)->bytes, (*ret)->len, (*ret)->d_size);
	fl = fmt->flgs ? fmt->flgs : 0;
	if (fl && *fl == '-')
		fl++;
	len = (*ret)->bytes;
	nbrs = ft_strdup((*ret)->data);
	if (fmt->width > (int)(*ret)->bytes)
	{
		//printf("yea 1\n");
		*ret = array_resize(*ret, fmt->width +  1);
		//printf("yea 1\n");
		(*ret)->bytes = (*ret)->len - 1;
	//	printf("yea 1\n");
		ft_memset((*ret)->data, (fl && *fl == '0') ? '0' : ' ', fmt->width);
		//printf("memset: '%s'	len: '%zu'\n", (char *)(*ret)->data, len);
		if (fmt->flgs && fmt->flgs[0] == '-')
		{
			//printf("case 1\n");
			ft_memcpy((*ret)->data, nbrs, len);
		}
		else
		{
			//printf("case 2\n");
			ft_memcpy((*ret)->data + len, nbrs, len);
		}
	}
	//printf("last : '%s'\n", (char *)(*ret)->data);
	ft_strdel(&nbrs);
}


/*

agv = printfstrdup(va_arg(*ap, char *));
sp = fmt->flgs ? fmt->flgs : 0;
if ((sp) && *sp == '-')
	sp++;
if (fmt->prec < (int)ft_strlen(agv) && fmt->prec > 0)
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
		ft_strncpy(str->data + (str->bytes - len), agv, len);
}
ft_strdel(&agv);

*/


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
		format_integer(fmt, &ret, type, 1);	//check if integer needs to be formated, ex: 0
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

#include "ft_printf.h"
#include <inttypes.h>



static void	format_integer(t_agv *fmt, t_array **ret, char t)//free old integer
{
	char	*nbr;
	char	*f;
	size_t	sp;
	char	pl;

	(void)t;
//	printf("flgs: '%s'\n", fmt->flgs);
	f = fmt->flgs && fmt->flgs[0] == '-' ? fmt->flgs + 1 : fmt->flgs;	//f is flag after '-' or 0
	nbr = ft_strdup((*ret)->data);	//get copy of nbr, with '-' if neg
	pl = (ft_strchr(f, '+') && ft_atoi((*ret)->data)) ? 1 : 0;	//just 1 if sign needed
	sp = (int)(*ret)->bytes > fmt->prec ? 0: (fmt->prec - (*ret)->bytes);	//sp is now # of 0 needed for prec
	sp = (f && (*f == '0' || *f == ' ')) ? sp + 1: sp;	//sp + 1 if need to append based on *f '0' or ' '
//	printf("nbr '%s'\n", nbr);
//	printf("appending prec, 0, sp:'%zu', sign:'%d' \n", sp, pl);
	if (sp || pl)//if need to append sign, prec spaces or first '0'/' '
	{
	//	printf("appending prec, 0, sp:'%zu', sign:'%d' \n", sp, pl);
		*ret = array_resize(*ret, (*ret)->len + sp + pl);
		(*ret)->bytes = (*ret)->len - 1;
	//	printf("resized bytes [%zu]\n", (*ret)->bytes);
		ft_memset((*ret)->data, ' ', (*ret)->bytes);
		ft_memset((*ret)->data + pl + sp, '0', sp);
		ft_memcpy((*ret)->data + pl + sp, nbr && *nbr == '-' ? nbr + 1 : nbr,
		ft_strlen(nbr && *nbr == '-' ? nbr + 1 : nbr));
	}
	if (fmt->width > (int)(*ret)->bytes)
	{
		//printf("appending width '%zu'\n", fmt->width - (*ret)->bytes);
		(*ret) = array_resize(*ret, (*ret)->len + sp + fmt->width - (*ret)->bytes);
		(*ret)->bytes = (*ret)->len - 1;
		//printf("resized bytes [%zu]\n", (*ret)->bytes);
		//printf("at : '%zu'\n", pl + ((*ret)->bytes - fmt->width));
		ft_memset((*ret)->data, (f && *f == '0') ? '0' : ' ', (*ret)->bytes);
		//printf("spaces '%s'\n", (char *)(*ret)->data);
		if (fmt->flgs && fmt->flgs[0] == '-')
		{
			ft_memcpy((*ret)->data + pl, nbr, ft_strlen(nbr));
		}
		else
		{
			ft_memcpy((*ret)->data + pl + (*ret)->bytes - (ft_strlen(nbr && *nbr
			== '-' ? nbr + 1 : nbr)), nbr && *nbr == '-' ? nbr + 1 : nbr,
			ft_strlen(nbr && *nbr == '-' ? nbr + 1 : nbr));
		}
	//	ft_memcpy((*ret)->data + (fmt->width - (*ret)->bytes), nbr, ft_strlen(nbr) - 1);
	}
	if (pl)
		ft_memset((*ret)->data, *nbr == '-' ? '-' : '+', 1);
//	printf(" |%s|\n", (char *)(*ret)->data);
	/* manage adding 0 to str->data if needed as prec */
	/* if width > len append min width */
		/* get value of spaces ' ' or '0' */
		/* if '-' flag is set append spaces to the left, else; to the right*/
	/* if pl append '+' or '-' according to sign */
	//put = ft_strchr(fmt->flgs, '0') ? '0' : ' ';
	ft_strdel(&nbr);
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
		format_integer(fmt, &ret, type);	//check if integer needs to be formated, ex: 0
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

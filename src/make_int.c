#include "ft_printf.h"
#include <inttypes.h>

static void	format_integer(t_agv *fmt, t_array **ret)//free old integer
{
	int		num;
	size_t	skip;
	char	sp;

	skip = 0;
	sp = ' ';
	num = ft_atoi((*ret)->data);
	if (fmt->flgs)
		printf("fmt->flgs '%s'\n", fmt->flgs);
	if (fmt->flgs && ft_strnchr(fmt->flgs, '+', 2) && num >= 0)
		append_char(ret, ++skip, '+');
	else if (fmt->flgs && fmt->flgs[0] == ' ' && num >= 0)
		append_char(ret, ++skip, ' ');
	if (fmt->flgs && fmt->flgs[skip] == '0' && (fmt->prec == 1))
		sp = '0';
	if (fmt->prec > (int)(*ret)->bytes)
		append_atchar(ret, skip + ISNEG(num), (fmt->prec -
			((*ret)->bytes - ISNEG(num))) + skip, '0');
	if (fmt->width > (int)(*ret)->bytes)
	{
		if (fmt->flgs && fmt->flgs[0] == '-')
			cat_char(ret, fmt->width - (int)(*ret)->bytes, sp);
		else
		{
			printf("data-> '%s'\n", (char *)(*ret)->data);
			append_atchar(ret, skip + ISNEG(num), fmt->width -
				(int)(*ret)->bytes, sp);
		}
	}
}

/* if pl append '+' or '-' according to sign */
/* manage adding 0 to str->data if needed as prec */
/* if width > len append min width */
	/* get value of spaces ' ' or '0' */
	/* if '-' flag is set append spaces to the left, else; to the right*/

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
	if (type != 'n' && ret)
		format_integer(fmt, &ret);
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
		tmp.data = ft_uitoa_base(va_arg(*ap, size_t), fmt->base);
	else if (lmod && !ft_strcmp(lmod, "ll"))
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (ft_isupper(fmt->type) || *lmod == 'l')
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	else if (*lmod == 'h')
		tmp.data = ft_uitoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 'j')
		tmp.data = ft_ulltoa_base(va_arg(*ap, uintmax_t), fmt->base);
	else if (*lmod == 'z')
		tmp.data = ft_ulltoa_base(va_arg(*ap, size_t), fmt->base);
	else if (*lmod == 't')
		tmp.data = ft_ulltoa_base(va_arg(*ap, unsigned long long), fmt->base);
	tmp.len = (ft_strlen(tmp.data) + 1);
	tmp.bytes = tmp.len - 1;
	return (array_clone(&tmp));
}

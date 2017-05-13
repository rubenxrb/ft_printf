/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static void testing_agv(t_agv *fmt)
{
	static int count = 1;
	printf("--- var [%d] ----\n", count++);
	printf("fmt->flgs [%s]\n", fmt->flgs);
	printf("fmt->width [%d]\n", fmt->width);
	printf("fmt->prec [%d]\n", fmt->prec);
	printf("fmt->l_mod [%s]\n", fmt->l_mod);
	printf("fmt->type [%c]\n", fmt->type);
	printf("fmt->base [%zu]\n", fmt->base);
	printf("-----------------\n");
}

STRING
s, S[l] = char * , wchar *

INTEGERS: [hh, h, l, ll, j, z, t]		<if 'l' used in c, convert to uns char>
c,C[l], d,D, i, n = signed numbers			<note: c can just have 'l' lenmod>
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

static t_byte	send_length(size_t len, int *dest)
{
	if (dest)
	{
		*dest = len;
		return (1);
	}
	return (0);
}

static t_array *convert_format(t_agv *fmt, va_list *ap)
{
	t_array	*new;	//new.data <free@lisof_vars()>
	char	t;
	char	lmod;

	new = 0;
	t = fmt->type;
	lmod = fmt->l_mod ? fmt->l_mod[0] : 0;
	if (ft_isletter(t, 's'))
		new = (t == 'S'|| lmod == 'l') ? make_wstr(fmt, ap) : make_str(fmt, ap);
	else if (ft_isletter(t, 'd') || ft_isletter(t, 'c') || t == 'i' || t == 'n')
		new = make_signed(fmt, t, ap);
	else if (ft_isletter(t, 'o') || ft_isletter(t, 'x') || t == 'u')
	{
		new = make_uint(fmt, fmt->l_mod, ap);
		new->data = (t == 'x') ? strtolower(new->data) : new->data;
	}
	else if (ft_isletter(t,'f') || ft_isletter(t, 'e') || ft_isletter(t, 'g'))
		new = make_decimal(fmt, t, ft_islower(t), ap);
	else if (ft_isletter(t, 'a'))
		new = make_fhex(fmt, ft_islower(t), ap);
	else if (t == 'p' || t == '%' || t == 'k' || t == '~')
		new = make_utils(fmt, t, ap);
	return (new);
}

static t_agv *extract_fmt(const char *s)
{
	t_agv	*ret;
	char	*fmt;
	char	*t;

	ret = ft_memalloc(sizeof(t_agv));		//<free@listof_vars()>
	fmt = get_format(s);					//<free@bottom>
	t = fmt;
	if (isFlag(*t))
		t += set_flags(ret, t);				//<free@listof_vars()>
	if ((*t == '*') || ft_isdigit(*t))
		t += set_minwidth(ret, t);
	if (*t == '.' && ((*(t + 1) == '*') || (ft_isdigit(*(t + 1)))))
		t += set_prec(ret, t) + 1;
	if (isModif(*t))
		t += set_lmod(ret, t);				//<free@listof_vars()>
	if (isSpecifier(*t) && (ret->type = *t))
		ret->base = set_base(ret->type);
	else
		display_error(fmt);
	ft_strdel(&fmt);
	return (ret);
}

//MAKE THE LIST SO IT HOLDS A T_ARRAY PER NODE, INSTEAD OF STRING
t_lst	listof_vars(const char *s, va_list *ap)
{
	t_lst	vars;			//<free@printf_fd>
	t_array	*current;
	t_agv	*fmt;
	size_t	i;

	ft_bzero(&vars, sizeof(t_lst));
	if (!s || !ap)
		return (vars);
	i = 0;
	while (*s)
	{
		if (*s++ == '%' && (fmt = extract_fmt(s)))
		{
			fmt->prec = fmt->prec < 0 ? va_arg(*ap, int) : fmt->prec;
			fmt->width = fmt->width < 0 ? va_arg(*ap, int) : fmt->width;
			current = convert_format(fmt, ap);
			i += current->bytes;
			if (*s == 'n' && send_length(i, current->data))
				ft_memdel(&current->data);
			lst_addarray(&vars, current);
		}
		else
			i++;
	}
	return (vars);
}

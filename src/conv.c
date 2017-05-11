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

*/

static t_array convert_format(t_agv *fmt, va_list *ap)
{
	t_array	new;
	char	t;

	new.data = ft_strdup("lol");
	t = fmt->type;
	if (t == 's')
		new.data = (t == 'l') ? make_wstr(fmt) : make_str(fmt);
	else if (t == 'c' || t == 'd' || t == 'i' || t == 'n')
		new.data = make_signed(fmt, t);
	else if (t == 'o' || t == 'O' || t == 'x' || t == 'X' || t == 'u')
		new.data = make_unsigned(fmt, t);
	else if (t == 'f' || t == 'F' || t == 'e' || t == 'E' || t == 'g' ||
			t == 'G')
		new.data = make_decimal(fmt, t);
	else if (t == 'a' || t == 'A')
		new.data = make_fhex(fmt);
	else if (t == 'p')
		new.data = make_ptr(fmt);
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
	if (*t == '.' && ((*t == '*') || (ft_isdigit(*(t + 1)))))
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

t_lst	listof_vars(const char *s, va_list *ap)
{
	t_lst	vars;			//<free@printf_fd>
	t_array	current;
	t_agv	*fmt;

	ft_bzero(&vars, sizeof(vars));
	if (!s || !ap)
		return (vars);
	while (*s)
	{
		if (*s++ == '%')
		{
			ft_bzero(&current, sizeof(t_array));
			fmt = extract_fmt(s);
			testing_agv(fmt);
			current = convert_format(fmt, ap);
			lst_addstr(&vars, current.data);
			ft_memdel(&current.data);
			ft_strdel(&fmt->flgs);
			ft_strdel(&fmt->l_mod);
			s = skip_fmt(s + 1);
		}
	}
	return (vars);
}

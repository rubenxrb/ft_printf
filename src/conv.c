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
#include <stdlib.h>

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
	printf("fmt->param [%d]\n", fmt->param);
	printf("-----------------\n");
}
*/

static void		send_length(int len, t_array *var)
{
	int	*dest;


	dest = var->data;
	*dest = len;
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
		new = (t == 'S'|| lmod == 'l') ? make_wstr(ap) : make_str(fmt, ap);
	else if (ft_isletter(t, 'd') || ft_isletter(t, 'c') || t == 'i' || t == 'n')
		new = make_signed(fmt, t, ap);
	else if (ft_isletter(t, 'o') || ft_isletter(t, 'x') || ft_isletter(t, 'u'))
	{
		new = make_uint(fmt, fmt->l_mod, ap);
		new->data = (t == 'x') ? strtolower(new->data) : new->data;
		if (fmt->flgs && fmt->flgs[0] == '#')
			uint_prefix(&new, t);
	}
	else if (ft_isletter(t,'f') || ft_isletter(t, 'e') || ft_isletter(t, 'g'))
		new = make_decimal(fmt, t, ft_islower(t), ap);
	else if (ft_isletter(t, 'a'))
		new = make_fhex(fmt, ft_islower(t), ap);
	else if (t == '%' || t == 'k' || t == 'p' || t == '~' || t == 'r')
		new = make_utils(fmt, t, ap);
	return (new);
}

static t_agv *extract_fmt(const char *s)
{
	t_agv	*ret;
	char	*fmt;
	char	*t;

	ret = ft_memalloc(sizeof(t_agv));		//<free@listof_vars()>
	if (!(fmt = get_format(s)))
		return (0);
	ret->param = 1;
	t = fmt;
	if (t && (isFlag(*t) || ft_isdigit(*t)))
		t += set_flags(ret, t);				//<free@listof_vars()>
	if ((*t == '*') || ft_isdigit(*t))
		t += set_minwidth(ret, t);
	if (*t == '.' && (*(t + 1) == '*' || ft_isdigit(*(t + 1)) ||
		isSpecifier(*(t + 1))))
		t += isSpecifier(*(t + 1)) ? 1 : set_prec(ret, t) + 1;
	if (isModif(*t))
		t += set_lmod(ret, t);				//<free@listof_vars()>
	ret->type = *(fmt + (ft_strlen(fmt) - 1));
	if (!isSpecifier(ret->type))
		ft_memdel((void **)&*ret);
	ret->base = set_base((ret->type = *t));
	ft_strdel(&fmt);
	return (ret);
}

static void var_found(t_lst *vars, int *len, t_agv *fmt, va_list ap)
{
	t_array	*current;
	va_list	tmp;

	current = 0;
	fmt->width = fmt->width < 0 ? va_arg(ap, int) : fmt->width;
	fmt->prec = fmt->prec < 0 ? va_arg(ap, int) : fmt->prec;
	if (fmt->param > 1)
	{
		va_copy(tmp, ap);
		while (fmt->param > 1 && va_arg(tmp, void *))
			fmt->param--;
		current = convert_format(fmt, &tmp);
		va_end(tmp);
	}
	else
		current = convert_format(fmt, (va_list *)ap);
	if (fmt->type == 'n')
		send_length(*len, current);
	else if (current && current->d_size)
	{
		lst_addarray(vars, current);
		*len += SUM_SIZE(current->d_size);
	}
}

//MAKE THE LIST SO IT HOLDS A T_ARRAY PER NODE, INSTEAD OF STRING
t_lst	*listof_vars(const char *s, va_list ap)
{
	t_lst	*vars;			//<free@printf_fd>
	t_agv	*fmt;
	int		i;

	if (!s || !ap || !(vars = ft_memalloc(sizeof(t_lst))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s++ == '%' && (fmt = extract_fmt(s)))
		{
			if (!fmt || !fmt->type)
				return (vars);
			var_found(vars, &i, fmt, ap);
			s = skip_fmt(s);
			ft_strdel(&fmt->l_mod);
			ft_strdel(&fmt->flgs);
			ft_memdel((void **)&fmt);
		}
		else
			i++;
	}
	return (vars);
}

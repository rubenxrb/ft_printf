/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:18:38 by rromero           #+#    #+#             */
/*   Updated: 2017/01/29 18:18:39 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_fd(const int fd, const char *s, ...)
{
	va_list	av_lst;
	t_lst	cv_lst;
	t_node	*curr;
	size_t	len;

	va_start(av_lst, s);
	cv_lst = listof_vars(s, &av_lst);							//format check
	if (!(curr = cv_lst.head) && ft_strchr(s, '%'))
		return (0);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			len += print_var(curr->data, fd, *(s + 1));
			array_destroy(curr->data);
			s = skip_fmt(s + 1);
			curr = curr->next;
		}
		else
			len += ft_putchar_fd(*s++, fd);
	}
	va_end(av_lst);
	ft_lstdel((t_node **)&cv_lst.head, ft_bzero);
	return (len);
}

int		ft_printf(const char *s, ...)
{
	va_list	av_lst;
	t_lst	cv_lst;
	t_node	*curr;
	size_t	len;

	va_start(av_lst, s);
	cv_lst = listof_vars(s, &av_lst);							//format check
	if (!(curr = cv_lst.head) && ft_strchr(s, '%'))
		return (0);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			len += print_var(curr->data, 1, *(s + 1));
			*(s + 1) == 'n' ? s : array_destroy(curr->data);
			s = skip_fmt(s + 1);
			curr = curr->next;
		}
		else
			len += ft_putchar(*s++);
	}
	va_end(av_lst);
	ft_lstdel((t_node **)&cv_lst.head, ft_bzero);
	return (len);
}

/*
1st argument always has the # of agv as parameters
count = # of agv
va_list lst; -> ptr to list with agvs
va_start(lst, count); allocate lst, with count-# of agvs
*type* var = va_arg(lst,(*type*)); will return next arg of given type
the first use of va_arg macro after va_start returns the argument after
the last one. Successive invocations return the value of remaining agvs.
va_end(lst); free list

#include <stdarg.h>
void va_start(va_list ap, count);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
*/

/*
1 loop format string, print characters.
2 if (*format == '%')
	2.1 check format syntax
		2.1.2 check format order
	2.2 get format modifiers (prec, width, base)
	2.3 convert (var type)->(char *) using specified format
		2.3.1 (var type)->
	2.4 print converted variable->add count
3 else
	3.1 print current char(*format)->add count
*/

/*
FUNCTIONS I NEED
itoa for: [d, i] (signed int) | def prec = 1 | if !prec & !converted value = 0 - no chars
itooct for: [o] (unsigned int) | def prec = 1 | if !prec & !converted value = '0'
itohex for: [x, X] (unsigned int) | case sens | def prec = 1 | if !prec & !converted value = 0 - no chars
itoa for: [u] (unsigned int) | def prec = 1 | if !prec & !converted value = 0 - no chars
ftoa for: [f,F] (float) | def prec = 6 |
*/

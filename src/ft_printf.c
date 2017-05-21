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
#include <stdio.h>

int		printf_fd(const int fd, const char *s, ...)
{
	va_list	av_lst;
	t_lst	*cv_lst;
	t_node	*curr;
	size_t	len;

	va_start(av_lst, s);
	cv_lst = listof_vars(s, &*av_lst);							//format check
	curr = cv_lst->head;
	len = 0;
	while (*s)
	{
		if (*s == '%' && curr)
		{
			len += print_var(&curr, fd, *++s);
			s = skip_fmt(s);
		}
		else if (isModif(*s) && ft_isupper(*s))
			s++;
		else
			len += ft_putchar(*s++);
	}
	va_end(av_lst);
	ft_lstdel((t_node **)&cv_lst->head, ft_bzero);
	return (len);
}

int		ft_printf(const char *s, ...)
{
	va_list	av_lst;
	t_lst	*cv_lst;
	t_node	*curr;
	size_t	len;

	va_start(av_lst, s);
	cv_lst = listof_vars(s, &*av_lst);							//format check
	curr = cv_lst->head;
	len = 0;
	while (*s)
	{
		if (*s == '%' && curr)
		{
			len += print_var(&curr, 1, *++s);
			s = skip_fmt(s);
		}
		else
			len += ft_putchar(*s++);
	}
	va_end(av_lst);
	ft_lstdel((t_node **)&cv_lst->head, ft_bzero);
	return (len);
}

t_lst	*printf_lst(const char *s, ...)
{
	va_list	av_lst;
	t_lst	*cv_lst;

	va_start(av_lst, s);
	cv_lst = listof_vars(s, &*av_lst);
	va_end(av_lst);
	return (cv_lst);
}

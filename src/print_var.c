/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:29 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

size_t			print_var(t_node **node, const int fd, const char nxt)
{
	t_array	*str;
	wchar_t *lol;

	if (nxt == 'n' || !*node)
		return (0);
	str = (*node)->data;
	*node = (*node)->next;
	lol = str->data ? str->data : 0;
	if (str->d_size > 1)
	{
		if (str->bytes > 1 && str->len > 1)
			return wstrput_fd(str->data, fd, str->len);
		else if (str->len == 1 && str->bytes > 1)
			return ft_putstr_fd(str->data, fd);
		else
			return (ft_putchar_fd(*lol, fd));
	}
	return ft_putstr_fd(str->data, fd);
}

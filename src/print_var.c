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

size_t	print_var(size_t len, t_node *var, const int fd)
{
	//ft_putendl("printvar");
	t_array	*str;
	size_t	ln;
	int		*n;

	//ft_putendl("printvar");
	str = var->data;
	ln = ft_putstr_fd(str->data, fd);
	if (!str->data)
	{
		ft_putendl("N FLAG");
		n = str->data;
		*n = len;
	}
	return ln;
}

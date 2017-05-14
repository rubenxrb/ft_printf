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

size_t			print_var(t_array *str, const int fd)
{
	//printf("bytes: '%zu' len: '%zu' d_size: '%zu'\n", str->bytes, str->len, str->d_size);
	//if (str->d_size > 1)
		//return wstrput_fd(str->data, fd, str->bytes);
//	else
	if (str->data)
		return ft_putstr_fd(str->data, fd);
	return (0);
}

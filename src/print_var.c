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
#include <stdlib.h>

size_t			print_var(t_array *str, const int fd, const char nxt)
{
	wchar_t	*lol;

	lol = str->data ? str->data : 0;
//	printf("%d\n", *lol);
	if (str->d_size > 1)
		if (*lol < 0 || (*lol > 55295 && *lol < 57344) || *lol > 1114111)
			exit(-1);
	//printf("bytes: '%zu' len: '%zu' d_size: '%zu'\n", str->bytes, str->len, str->d_size);
	//if (str->d_size > 1)
		//return wstrput_fd(str->data, fd, str->bytes);
//	else
//	printf("PRINTVAR\n");
	char	*d;
	d = str->data;
	if (nxt == 'c' && !*d)
		return (1);
	return ft_putstr_fd(str->data, fd);
}

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

	(void)nxt;
	lol = str->data ? str->data : 0;
//	printf("%d\n", *lol);
//	if (str->d_size > 1)
	//	if (*lol < 0 || (*lol > 55295 && *lol < 57344) || *lol > 1114111)
		//{
	//		printf("EXITING\n");
			//exit(-1);
		//}
//	printf("bytes: '%zu' len: '%zu' d_size: '%zu'\n", str->bytes, str->len, str->d_size);
	//printf("wchar_len: '%zu'\n", wchar_len(*lol));
//	if (str->d_size > 1)
	//	return wstrput_fd(str->data, fd, wchar_len(*lol));
//	else if (nxt == 'c' && !*d)
	//	return (1);
	return write(fd, str->data, str->bytes);
}

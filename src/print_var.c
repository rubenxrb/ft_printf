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

	(void)nxt;
	if (nxt == 'n')
	{
		//printf("ret 0\n");
		//node = node->next ? node->next : 0;
		return (0);
	}
	str = (*node)->data;
	*node = (*node)->next;
	//node = node->next;
//	node = node->next;
	//str->bytes = (nxt == 'c') ? 1 : str->bytes;
	wchar_t *lol = str->data ? str->data : 0;
//	printf("%d\n", *lol);
	//if (str->d_size > 1)
//		if (*lol < 0 || (*lol > 55295 && *lol < 57344) || *lol > 1114111)
	//	{
			//printf("EXITING\n");
//			exit(-1);
	//}
//	printf("bytes: '%zu' len: '%zu' d_size: '%zu'\n", str->bytes, str->len, str->d_size);
	//printf("wchar_len: '%zu'\n", wchar_len(*lol));
//	else if (nxt == 'c' && !*d)
	//	return (1);
	//printf("ENTERING PRINT_VAR node '%p'\n", node);
	if (str->d_size > 1)//not str
	{
		if (str->bytes > 1 && str->len > 1)
			return wstrput_fd(str->data, fd, str->len); //wc
		else if (str->len == 1 && str->bytes > 1)
			return ft_putstr_fd(str->data, fd);
		else
			return (ft_putchar_fd(*lol, fd));
	}
	return ft_putstr_fd(str->data, fd);
	array_destroy(str->data);
}

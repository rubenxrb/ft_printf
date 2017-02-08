/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 01:25:53 by rromero           #+#    #+#             */
/*   Updated: 2016/10/29 02:37:35 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)ft_memalloc(sizeof(t_list));
	if (!head)
		return (0);
	if (!content)
	{
		head->content = 0;
		head->content_size = 0;
	}
	else
	{
		head->content = (void *)ft_memalloc(content_size);
		if (!head->content)
		{
			free(head);
			return (0);
		}
		head->content = ft_memcpy(head->content, content, content_size);
		head->content_size = content_size;
	}
	head->next = 0;
	return (head);
}

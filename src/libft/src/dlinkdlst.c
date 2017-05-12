/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinklst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_dlnode	*dlnode_new(void const *data, size_t data_size)
{
	t_dlnode	*new;

	new = ft_memalloc(sizeof(t_dlnode));
	if (!new)
		return (0);
	if (!data)
	{
		new->data = 0;
		new->d_size = 0;
	}
	else
	{
		new->data = ft_memalloc(data_size);
		if (!new->data)
		{
			ft_memdel((void **)new);
			return (0);
		}
		new->data = ft_memcpy(new->data, data, data_size);
		new->d_size = data_size;
	}
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_byte	dlnode_del(t_dlnode **node, void (*bzero)(void *, size_t))
{
	if (!*node)
		return (0);
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	if ((*node)->prev)
		(*node)->prev->next = (*node)->next;
	bzero((*node)->data, (*node)->d_size);
	ft_memdel((void **)node);
	return (1);
}

size_t	dlinklst_del(t_dlnode **lst, void (*bzero)(void *, size_t))
{
	size_t	len;

	len = 0;
	if (*lst && bzero)
	{
		len += dlinklst_del(&(*lst)->next, bzero);
		dlnode_del(lst, bzero);
		len++;
	}
	return (len);
}

void	dlnode_addnext(t_dlnode *curr, t_dlnode *add)
{
	if (!curr || !add)
		return ;
	else
	{
		curr->next = add;
		add->prev = curr;
	}
	curr = add;
}

t_dlnode	*update_tail(t_dlnode *head)
{
	t_dlnode	*tail;

	if (!head)
		return (0);
	tail = head;
	while (head)
	{
		tail = head;
		head = head->next;
	}
	return (tail);
}

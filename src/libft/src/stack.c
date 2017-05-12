/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:05:42 by rromero           #+#    #+#             */
/*   Updated: 2017/03/23 09:09:45 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // snode_new, <s_push>, <s_pop>, <s_look> & <snode_del>

t_snode		*snode_new(void const *data, size_t d_size)
{
	t_snode	*new;

	new = ft_memalloc(sizeof(t_snode));
	if (!new)
		return (0);
	new->d_size = d_size;
	if (d_size && data)
	{
		new->data = ft_memalloc(d_size);
		if (!new->data)
		{
			ft_memdel((void **)new);
			return (0);
		}
		new->data = ft_memcpy(new->data, data, d_size);
	}
	return (new);
}

t_snode		*stack_push(t_snode *top, t_snode *new)
{
	if (!new || !top)
		return (0);
	new->prev = top;
	return (new);
}

t_snode		*stack_pop(t_snode *top)
{
	if (!top)
		return (0);
	return (top->prev);
}

t_snode		*stack_lookup(t_snode *top, t_snode *node)
{
	if (!top || !node)
		return (0);
	while ((top->prev) && top != node)
		top = top->prev;
	return (top == node ? node : 0);
}

void		snode_del(t_snode *node)
{
	if (node)
	{
		node->d_size = 0;
		if (node->data)
			ft_memdel(&node->data);
		ft_memdel((void **)&node);
	}
}

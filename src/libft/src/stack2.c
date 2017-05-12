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

#include "libft.h"	// <s_last>, <s_del>, <s_len>

t_snode		*stack_last(t_snode	*top)
{
	t_snode	*last;

	if (!top)
		return (0);
	last = top;
	while (last && last->prev)
		last = last->prev;
	return (last);
}

void		stack_del(t_snode *top)
{
	t_snode	*tmp;

	if (!top)
		return ;
	while (top)
	{
		tmp = top->prev;
		snode_del(top);
		top = tmp;
	}
}

size_t		stack_len(t_snode *top)
{
	size_t	size;

	if (top)
	{
		size = 0;
		while (top && size++)
			top = top->prev;
		return (size);
	}
	return (0);
}

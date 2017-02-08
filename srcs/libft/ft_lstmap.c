/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 01:31:09 by rromero           #+#    #+#             */
/*   Updated: 2016/10/15 01:31:10 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;

	if (!lst || !f)
		return (0);
	if (lst->next)
	{
		node = ft_lstmap(lst->next, f);
		ft_lstadd(&node, f(lst));
	}
	else
		node = f(lst);
	return (node);
}

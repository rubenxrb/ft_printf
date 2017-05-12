
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_dlnode	*split_dlinklst(t_dlnode **starting)
{
	t_dlnode	*fast;
	t_dlnode	*slow;
	t_dlnode	*tmp;

	fast = *starting;
	slow = *starting;
	while ((fast->next) && (fast->next->next))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	tmp = slow->next;
	slow->next = 0;
	return (tmp);
}

t_dlnode	*dlinklst_merge(t_dlnode *lst, t_dlnode *tmp, t_byte (*cmp)(void *, void *))
{
	if (!lst)
		return (tmp);
	if (!tmp)
		return (lst);
	if (cmp(lst->data, tmp->data) > 0)
	{
		lst->next = dlinklst_merge(lst->next, tmp, cmp);
		lst->next->prev = lst;
		lst->prev = 0;
		return (lst);
	}
	else
	{
		tmp->next = dlinklst_merge(lst, tmp->next, cmp);
		tmp->next->prev = tmp;
		tmp->prev = 0;
		return (tmp);
	}
}


t_dlnode	*dlinklst_sort(t_dlnode **head, t_byte (*cmp)(void *, void *))
{
	t_dlnode	*tmp;

	if (!*head || !(*head)->next)
		return (*head);
	tmp = split_dlinklst(head);
	*head = dlinklst_sort(head, cmp);
	tmp  = dlinklst_sort(&tmp, cmp);
	return (dlinklst_merge(*head, tmp, cmp));
}

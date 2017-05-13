#include "libft.h"

t_byte	lst_addstr(t_lst *list, const char *name)
{
	t_array		string;
	t_node		*add;

	if (!name)
		return (0);
	string.data = ft_strdup(name);
	string.d_size = 1;
	string.len = ft_strlen(name);
	string.bytes = (string.len + 1);
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_node *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
	return (1);
}

t_byte	lst_addwstr(t_lst *list, const wchar_t *name)
{
	t_array		string;
	t_node		*add;

	if (!name || !list)
		return (0);
	string.data = wstrdup(name);
	string.d_size = sizeof(wchar_t);
	string.len = wstrlen(name);
	string.bytes = ((string.d_size * string.len) + sizeof(wchar_t));
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_node *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
	return (1);
}

t_byte	lst_addarray(t_lst *list, t_array *add)
{
	t_node	*new;

	if (!add || !list)
		return (0);
	new = ft_memalloc(sizeof(t_node));
	new->data = add;
	if (!list->head)
	{
		list->head = new;
		list->tail = list->head;
	}
	else
	{
		((t_node *)(list->tail))->next = new;
		list->tail = new;
	}
	list->len++;
	return (1);
}

#include "libft.h"	// <arr_new>, <arr_resize>, <arr_clone>, <arr_look> & <arr_dstroy>

t_array	*array_new(size_t d_size, size_t len)
{
	t_array	*new;

	if (!d_size || !len)
		return (0);
	if (!(new = ft_memalloc(sizeof(t_array))))
		return (0);
	new->bytes = (d_size * len);
	if (!(new->data = ft_memalloc(new->bytes)))
	{
		ft_memdel((void **)new);
		return (0);
	}
	new->d_size = d_size;
	new->len = len;
	return (new);
}

t_array	*array_resize(t_array *old, size_t new_size)
{
	t_array	*new;

	if (!old || !new_size)
		return (0);
	if (!(new = ft_memalloc(sizeof(t_array))))
		return (0);
	new->data = 0;
	new->d_size = old->d_size;
	new->len = new_size;
	new->bytes = (new->d_size * new_size);
	if (!(new->data = ft_memalloc(new->bytes + old->d_size)))
	{
		ft_memdel((void **)new);
		return (0);
	}
	if (old->data)
	{
		new->data = ft_memcpy(new->data, old->data, old->bytes);
		ft_memdel(&old->data);
	}
	ft_memdel((void **)old);
	return (new);
}

t_array	*array_clone(t_array *src)
{
	t_array	*new;

	if (!src)
		return (0);
	if (!(new = ft_memalloc(sizeof(t_array))))
		return (0);
	new = ft_memcpy(new, src, sizeof(t_array));
	new->data = 0;
	if (!(new->data = ft_memalloc(new->bytes + new->d_size)))
	{
		ft_memdel((void **)new);
		return (0);
	}
	if (src->data)
		new->data = ft_memcpy(new->data, src->data, src->bytes);
	return (new);
}

void 	*array_look(t_array *curr, size_t index)
{
	if (curr && index < curr->len)
	{
		if (curr->data + (curr->d_size  * index))
			return (curr->data + (curr->d_size * index));
	}
	return (0);
}

void	array_destroy(t_array *curr)
{
	if (curr)
	{
		if (curr->data)
			ft_memdel(&curr->data);
		ft_memdel((void **)&curr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 03:05:25 by rromero           #+#    #+#             */
/*   Updated: 2017/01/18 03:05:27 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	if (new_size)
		new = (void *)ft_memalloc(new_size);
	if (((char *)ptr) && (size))
	{
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}

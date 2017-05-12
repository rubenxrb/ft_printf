/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memptrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:00:33 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:00:34 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //memalloc (malloc), bzero, memset, memdel & realloc
#include <stdlib.h>

void	*ft_memset(void *p, int c, size_t size)
{
	unsigned char	*a;

	a = p;
	while (size--)
		*a++ = c;
	return (p);
}

void	ft_bzero(void *b, size_t size)
{
	(void)ft_memset(b, 0, size);
}

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (!(p = (void *)malloc(size)))
		return (0);
	ft_bzero(p, size);
	return (p);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	if (!(new = ft_memalloc(new_size)))
		return (0);
	if (size && ptr)
	{
		new = ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}

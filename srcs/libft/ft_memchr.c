/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:35:30 by rromero           #+#    #+#             */
/*   Updated: 2016/10/01 15:35:31 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned int	i;

	ptr1 = (unsigned char *)s;
	i = 0;
	if (n > 0)
		while (n--)
		{
			if (*(ptr1 + i) == (unsigned char)c)
				return (&ptr1[i]);
			i++;
		}
	return (0);
}

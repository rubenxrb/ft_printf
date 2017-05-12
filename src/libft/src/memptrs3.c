/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memptrs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:36:12 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:36:13 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // memcmp, <empty>, <empty>, <empty> & <empty>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n > 0)
		while (n--)
			if (*p1++ != *p2++)
				return (*(--p1) - *(--p2));
	return (0);
}

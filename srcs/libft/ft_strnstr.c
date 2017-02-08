/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:24:13 by rromero           #+#    #+#             */
/*   Updated: 2016/10/05 17:24:15 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	length;

	if (!*little)
		return ((char *)big);
	length = ft_strlen(little);
	while (*big && len-- >= length)
	{
		if (*big == *little && !ft_memcmp(big, little, length))
			return ((char *)big);
		big++;
	}
	return (0);
}

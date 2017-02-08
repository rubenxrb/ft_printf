/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:35:30 by rromero           #+#    #+#             */
/*   Updated: 2016/10/08 16:35:32 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int			len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	while ((i < n) && (s2[i]))
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = 0;
	return (s1);
}

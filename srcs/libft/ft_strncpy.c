/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:43:53 by rromero           #+#    #+#             */
/*   Updated: 2016/09/27 22:43:54 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *t;

	t = dst;
	while ((len--) && (*src))
		*t++ = *src++;
	len++;
	while (len--)
		*t++ = '\0';
	return (dst);
}

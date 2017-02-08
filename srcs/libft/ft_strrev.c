/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:18:26 by rromero           #+#    #+#             */
/*   Updated: 2016/10/22 16:18:27 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*ps;
	char	*pf;
	char	tmp;

	if (!s || !*s)
		return ((char *)s);
	ps = (char *)s;
	pf = ps + (ft_strlen(s) - 1);
	while (pf > ps)
	{
		tmp = *ps;
		*ps++ = *pf;
		*pf-- = tmp;
	}
	return ((char *)s);
}

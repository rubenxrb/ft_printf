/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:42:35 by rromero           #+#    #+#             */
/*   Updated: 2016/09/27 22:42:37 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		e;

	e = 0;
	if (!*little)
		return ((char *)big);
	while (big[e])
		if (ft_strnequ(&big[e++], little, ft_strlen(little)))
			return ((char *)&big[--e]);
	return (0);
}

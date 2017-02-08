/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 22:20:23 by rromero           #+#    #+#             */
/*   Updated: 2016/10/14 22:20:24 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nextword(const char *s, char c, size_t *ele)
{
	size_t		i;

	i = 0;
	while (s[*ele] == c)
		*ele += 1;
	i = *ele;
	while (s[*ele])
	{
		if (s[*ele] == c)
			break ;
		*ele += 1;
	}
	return (ft_strsub(s, i, *ele - i));
}

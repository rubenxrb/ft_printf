/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:11:22 by rromero           #+#    #+#             */
/*   Updated: 2016/10/20 15:11:23 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;

	if (!s)
		return (0);
	p = ft_strnew(ft_strlen(s));
	i = 0;
	if (!p)
		return (0);
	while (s[i])
	{
		p[i] = f(s[i]);
		i++;
	}
	return (p);
}

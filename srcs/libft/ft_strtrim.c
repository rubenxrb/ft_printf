/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:42:55 by rromero           #+#    #+#             */
/*   Updated: 2016/10/12 20:28:54 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *p;

	if (!s)
		return (0);
	while (ft_iswhitespace(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	p = (char *)(s + (ft_strlen(s) - 1));
	while (ft_iswhitespace(*p))
		p--;
	return (ft_strsub(s, 0, (p - s + 1)));
}

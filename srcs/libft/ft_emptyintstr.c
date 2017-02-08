/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emptyintstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:04:31 by rromero           #+#    #+#             */
/*   Updated: 2016/10/14 13:04:32 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_emptyintstr(int n)
{
	char	*p;
	int		len;
	char	sign;

	sign = 0;
	len = ft_digitnum(n, 10);
	if (n < 0)
		sign++;
	p = ft_strnew(len + sign);
	if (!p)
		return (0);
	return (p);
}

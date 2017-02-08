/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:24:12 by rromero           #+#    #+#             */
/*   Updated: 2016/10/29 02:37:10 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*p;
	char	s;
	size_t	index;

	index = ft_digitnum(n, 10);
	if ((s = (n < 0) ? 1 : 0))
		index++;
	if (!(p = ft_strnew(index)))
		return (0);
	index = 0;
	if (n == 0 || !(n))
		p[index++] = '0';
	while (n)
	{
		p[index++] = (s ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	if (s)
		p[index++] = '-';
	p[index] = 0;
	return (ft_strrev(p));
}

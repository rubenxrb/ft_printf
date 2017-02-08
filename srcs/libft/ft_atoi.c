/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:29:28 by rromero           #+#    #+#             */
/*   Updated: 2016/10/29 02:36:36 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int n;
	int s;

	s = 0;
	n = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		str = (str + (++s));
	while (*str && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (s)
		return (-n);
	return (n);
}

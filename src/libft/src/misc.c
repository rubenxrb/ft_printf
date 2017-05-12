/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:45:17 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 02:45:17 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// digitnum, <empty>, <empty>, <empty> & <empty>

int					ft_numlen(int n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

int					ft_lnumlen(long n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

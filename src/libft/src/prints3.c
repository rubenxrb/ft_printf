/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:38:05 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:38:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// putnbr-nl, puthex, puthex-nl, set-color & <empty>

size_t	ft_puthex(int c, size_t prec)
{
	char	*hex;
	size_t	len;

	hex = ft_hextoa(c, prec);
	len = ft_putstr(hex);
	ft_strdel(&hex);
	return (len);
}

size_t	ft_puthexnl(int c, size_t prec)
{
	size_t	len;

	len = ft_puthex(c, prec);
	len += ft_putchar('\n');
	return (len);
}

void	set_color(int c)
{
	ft_putstr("\033[");
	ft_putnbr(c);
	ft_putchar('m');
}

void	print_bits(unsigned char octet)
{
	int d;

	d = 128;
	while (d)
	{
		if (d <= octet)
		{
			ft_putchar('1');
			octet = octet % d;
		}
		else
			ft_putchar('0');
		d /= 2;
	}
}

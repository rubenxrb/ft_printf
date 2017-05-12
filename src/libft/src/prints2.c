/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:16:24 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:16:25 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // putendl-fd, putnbr, putnbr-fd & putendl

size_t	ft_putendl(char const *s)
{
	size_t	len;

	len = ft_putstr(s);
	len += ft_putchar('\n');
	return (len);
}

size_t	ft_putendl_fd(char const *s, int fd)
{
	size_t	len;

	len = ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n / 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbrnl(int c)
{
	if (c)
	{
		ft_putnbr(c);
		ft_putchar('\n');
	}
}

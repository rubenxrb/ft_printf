/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:39:14 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:39:16 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // atoi, itoa, itoa-base, to-upper & to-lower

int		ft_atoi(const char *str)
{
	int n;
	int s;

	s = 0;
	n = 0;
	while (ft_isblank(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		str = (str + (++s));
	while (*str && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	return ((s) ? -n : n);
}

char	*ft_itoa(int n)
{
	char	*p;
	char	s;
	size_t	index;

	index = ft_numlen(n, 10);
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

char	*ft_itoa_base(int n, int b)
{
	char	*num;
	size_t	size;
	int		neg;
	int		mod;

	neg = 0;
	size = ft_numlen(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

int		ft_toupper(int c)
{
	if (ft_isalpha(c))
		if (c >= 97 && c <= 122)
			c -= 32;
	return (c);
}

int		ft_tolower(int c)
{
	if (ft_isalpha(c))
		if (c >= 65 && c <= 90)
			c += 32;
	return (c);
}

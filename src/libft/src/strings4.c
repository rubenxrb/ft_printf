/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:00:55 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:00:56 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // strdel, strclr, striter, striteri, strmap

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, (ft_strlen(s) + 1));
}

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = 0;
	if (s && f)
		while (s[i])
			f(&s[i++]);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = -1;
	if (s && f)
		while (s[++i])
			f(i, &s[i]);
}

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

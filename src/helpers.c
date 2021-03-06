/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

const char	*skip_fmt(const char *s)
{
	while (!isSpecifier(*s))
		s++;
	return (s + 1);
}

char	isModif(char c)
{
	char	valid[] = "hlLjzZt";			//added later hh, ll, j, z, t, L
	char	*p;

	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

/* if type specifier found, return it, else char != specifier */
char isSpecifier(char c)
{
	char valid[] = "sSpdDioOuUxXcCeEfFgGaAn%~kr";
	char	*p;

	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

char	isFlag(char c)
{
	char valid[] = "-0+# $";
	char	*p;

	p = valid;
	while (p && *p)
		if (c == *p++)
			return (c);
	return (0);
}

void	invalid_syntx(const char *s)
{
	(void)s;
	/*
	ft_putstr("ft_printf: ");
	putcstr("error", 91);
	ft_putstr(" invalid '");
	ft_putstr(s);
	ft_putendl("'");
	*/
//	exit(-1);
}

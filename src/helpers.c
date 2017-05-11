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

#include "ft_printf.h"
#include <stdlib.h>

const char	*skip_fmt(const char *s)
{
	while (!isSpecifier(*s))
		s++;
	return (s + 1);
}

char	isModif(char c)
{
	char	valid[] = "hljztL";			//added later hh, ll, j, z, t, L
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
	char valid[] = "sSpdDioOuUxXcCeEfFgGaAn%~k";
	char	*p;

	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

char	isFlag(char c)
{
	char valid[] = "-0+# ";
	char	*p;

	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

void	display_error(const char *s)
{
	printf("display error: %s\n", s);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:48:04 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:48:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // is-blank, *is-emoji, <empty>, <empty> & <empty>

int		ft_isblank(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
	|| c == '\r'));
}

int		ft_ishex(int c)
{
	return ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || ft_isdigit(c));
}

int		ft_ishexstr(const char *hex)
{
	char	*t;

	if (!hex)
		return (0);
	t = (char *)hex;
	if (!ft_strncmp(hex, "0x", 2))
		t = (char *)hex + 2;
	while (*t)
	{
		if (!ft_ishex(*t++))
			return (0);
	}
	return (1);
}

int		ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

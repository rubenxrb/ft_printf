/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:46:36 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:46:37 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // is-alpha, is-digit, is-alnum, is-ascii & is-printable

int		ft_isalpha(int c)
{
	return (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')));
}

int		ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int		ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

int		ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}

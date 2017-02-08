/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 22:39:38 by rromero           #+#    #+#             */
/*   Updated: 2016/10/14 22:39:39 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		words;
	size_t	element;

	index = 0;
	element = 0;
	words = ft_wordcount(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	while (index < words)
		str[index++] = ft_nextword(s, c, &element);
	str[index] = 0;
	return (str);
}

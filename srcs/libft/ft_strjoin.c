/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 20:33:17 by rromero           #+#    #+#             */
/*   Updated: 2016/09/23 20:33:18 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	if (!s1 || !s2)
		return (0);
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!s3)
		return (0);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}

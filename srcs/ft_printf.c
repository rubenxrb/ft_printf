/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:18:38 by rromero           #+#    #+#             */
/*   Updated: 2017/01/29 18:18:39 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

/*
t_list		get_params(const char *format)
{
	t_list	agv_lst;
	t_param	*av;
	size_t	count;

	agv_lst = ft_lstnew(666, 420);
	return agv_lst;
}
*/

int	ft_printf(const char *format, ...)
{
	char	*str = "this is test";
	char	*s2 = ft_strdup(str);
	int 	i = 0;
	int		nb[5];
	va_list agv;
	//t_list	ag_lst;

	(void)va_start(agv, format);
	ft_putendl(s2);
	while ( i < 5 )
		nb[i++] = va_arg(agv, int);
	i = 0;
	while (i < 5)
	 	{ printf("nb[%d] = %d\n", i, nb[i]); i++; }
	free(s2);
	return 0;
}


/*
1st argument always has the # of agv as parameters
count = # of agv
va_list lst; -> ptr to list with agvs
va_start(lst, count); allocate lst, with count-# of agvs
*type* var = va_arg(lst,(*type*)); will return next arg of given type
the first use of va_arg macro after va_start returns the argument after
the last one. Successive invocations return the value of remaining agvs.
va_end(lst); free list

#include <stdarg.h>
void va_start(va_list ap, count);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
*/

/*
1. create list of agvs
2. read input format string, validation
3. create list of params, count current # of params, populate format struct
4. read format struct, convert data to str, point [t_param list->av] to str
5. merge base_str + av[n] + base_str + av[n + 1] ...
6. print the string & free it
*/

/*
FUNCTIONS I NEED
itoa for: [d, i] (signed int) | def prec = 1 | if !prec & !converted value = 0 - no chars
itooct for: [o] (unsigned int) | def prec = 1 | if !prec & !converted value = '0'
itohex for: [x, X] (unsigned int) | case sens | def prec = 1 | if !prec & !converted value = 0 - no chars
itoa for: [u] (unsigned int) | def prec = 1 | if !prec & !converted value = 0 - no chars
ftoa for: [f,F] (float) | def prec = 6 |
*/

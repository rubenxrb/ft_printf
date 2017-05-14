#include "libft.h"
#include <stdio.h>

char	*uint_tostr(unsigned int num, int b)
{
	//char	*ret;
	size_t	size;

 	size= ft_numlen(num, b);
	printf("uint size : %zu\n", size);
	return (0);
}

char	*ulint_tostr(unsigned long long num, int b)
{
	//char	*ret;
	size_t	size;

 	size= ft_ulnumlen(num, b);
	printf("ulint size : %zu\n", size);
	return (0);
}

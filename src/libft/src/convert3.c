#include "libft.h"
#include <stdio.h>

char	*uint_tostr(unsigned int num, int b)
{
	//char	*ret;
	(void)num;
	(void)b;
//	size_t	size;

 //	size= ft_numlen(num, b);
//	printf("uint size : %zu\n", size);
	return (0);
}

char	*ulint_tostr(unsigned long long num, int b)
{
	//char	*ret;
	(void)num;
	(void)b;
	//size_t	size;

 	//size= ft_ulnumlen(num, b);
	//printf("ulint size : %zu\n", size);
	return (0);
}

char	*ft_uitoa_base(unsigned int n, int b)
{
	char	*num;
	size_t	len;
	size_t	mod;

	len = ft_unumlen(n, b);
	num = ft_strnew(len);
	while (len--)
	{
		mod = n % b;
		num[len] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

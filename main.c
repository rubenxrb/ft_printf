#include "ft_printf.h"

int main()
{
	char		*test = "agv1";
	char		*test2 = "agv2";
	size_t		num = 420;
	long long 	num2 = 111222333444;
	int			*cell;


	putcstr("libft printf:\n", 93);
	ft_printf("test: [%n] test2: [%s] num[%lld]\n", cell, test2, num2);
	ft_printf("test: [%c]\n", *(test + 2));
	//ft_printf("test: [%n]\n", cell);
	//ft_printf("cell: '%d'\n", *cell);
	//putcstr("stdlib printf:\n", 31);
	//printf("test: [%n]\n", cell);
	printf(" '%lld'\n", num2);
	printf(" '%c'\n", *(test + 2));
	return (0);
}

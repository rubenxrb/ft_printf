#include "ft_printf.h"

int main()
{
	char		*test = "agv1";
	char		*test2 = "agv2";
	size_t		num = 420;
	long long 	num2 = 111222333444;
	int			cell = 7;


	printf("cell '%p'\n", &cell);
	putcstr("libft printf:\n", 93);
	ft_printf("test: [%lld] test2: [%n] num[%s]\n", num2, &cell, test2 + 3);
	ft_printf("test: [%d]\n", cell);
	//ft_printf("test: [%n]\n", cell);
	//ft_printf("cell: '%d'\n", *cell);
	//putcstr("stdlib printf:\n", 31);
	//printf("test: [%n]\n", cell);
	printf(" '%lld'\n", num2);
	printf(" '%0c'\n", *(test));
	return (0);
}

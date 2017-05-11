#include "ft_printf.h"

int main()
{
	char		*test = "agv1";
	char		*test2 = "agv2";
	size_t		num = 420;
	long long 	num2 = 111222333444;

	putcstr("libft printf:\n", 93);
	ft_printf("test: [%3.*s] test2: [%ls] num: [%-#8.2f] long:[%-.3lld] test5: [%%]\n", 1, test, test2, num, num2);
	putcstr("stdlib printf:\n", 31);
	printf("'test: [%-8.3s] test2: [%s] num: [%-8.2zd] long[%-.3lld]'\n", test, test2, num, num2);
	printf("%3.1s\n", test);
	return (0);
}

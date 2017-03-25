#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	ft_printf("this is test [%5D], [%%pe], [%666f], [%-420A]\n", 1, 2, 3, 8);
	return 0;
}

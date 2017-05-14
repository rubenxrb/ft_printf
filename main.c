#include "ft_printf.h"

int main()
{
	//work  on [%-.s]
	wchar_t		kat = 0x3A0;
	char		*test2 = "printed";
	size_t		num = 420;
	long long 	num2 = 111222333444;
	wint_t		num3 = 555666777;
	char		num4 = 9;
	int			cell = 7;
	size_t		sz = 600500400300;

	putcstr("libft printf:\n", 93);
	//wcharput_fd(kat, 1);
	printf("bytes { %lc }\n", kat);
	ft_printf("bytes [ %lc ]\n", kat);

//	printf("cell '%p'\n", &cell);
//	ft_printf("test: [%lld] test2: [%n] num[%s]\n", num2, &cell, test2 + 3);
	//ft_printf("test: [%n]\n", cell);
	//ft_printf("cell: '%d'\n", *cell);
	//putcstr("stdlib printf:\n", 31);
	//printf("test: [%n]\n", cell);
	//printf(" '%lld'\n", num2);
	return (0);
}

/*
t_array	*ret;
char	*lmod;
t_byte	wc;
int		ch;

ret = 0;
lmod = fmt->l_mod ? fmt->l_mod : 0;
if (ft_isletter(type, 'c'))
{
	wc = (lmod && lmod[0] == 'l') || ft_isupper(type);
	ret = array_new(wc ? sizeof(wint_t) : sizeof(int), 1);
	if (wc && (ch = va_arg(*ap, wint_t)))
		ft_memcpy(ret->data, &ch, sizeof(wint_t));
	else if ((ch = va_arg(*ap, int)))
		ft_memcpy(ret->data, &ch, sizeof(int));
}
else if (ft_isletter(type, 'd') || type == 'i' || type == 'n')
{
	fmt->prec = fmt->prec ? fmt->prec : 1;
	ret = make_sint(fmt, lmod, ap);
}
if (type != 'n' && ret)
	format_integer(fmt, ret, type, 1);

*/

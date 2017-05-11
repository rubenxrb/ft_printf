#include "ft_printf.h"
#include <stdlib.h>

void	*make_str(t_agv *fmt, va_list *ap)
{
	char	*str;
//	size_t	s_len;
	char	*agv;
	//char	*tmp;	//<free@bottom>
	size_t	spc;

	spc = 0;
	agv = va_arg(*ap, char *);
//	tmp = ft_strsub(agv, 0, s_len);
	if (fmt->width > fmt->prec)
		spc = fmt->width - fmt->prec;
	//s_len = spc - ft_strlen(agv);
	(void)agv;
	printf("spaces: '%zu', tocpy '%d'\n", spc, );
	exit(1);
	return (str);
}

void	*make_wstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

void	*make_cstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}


void	*make_cwstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return ft_strdup(&fmt->type);
}

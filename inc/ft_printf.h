/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:49:41 by rromero           #+#    #+#             */
/*   Updated: 2017/01/31 23:41:53 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)

# include <stdarg.h>		//<...> args
# include <stdio.h>			//actual printf
# include <wchar.h>			//wide characters
# include "libft.h"

typedef struct	s_agv		//data in list
{
	char		*flgs;			//string of flags [done]
	int			width;			//0 default, -1 if wildcard [done]
	int			prec;			//precission after '.' [done]
	char		*l_mod;			//string with length modifier [done] <heap>
	char		type;			//variable type [done]
	size_t		base;			//base of number [get]
	size_t		len;
}				t_agv;

/* ft_printf.c */
int				ft_printf(const char *s, ...);
int				printf_fd(const int fd, const char *s, ...);
int				printf_buf(void **dest, const char *s, ...);

/* conv.c	*/
t_lst			listof_vars(const char *s, va_list *ap);

/* get_var.c */
char			*get_format(const char *_format);

/* read_var.c */
size_t			set_flags(t_agv *ret, const char *fmt);
size_t			set_minwidth(t_agv *ret, const char *fmt);
size_t			set_prec(t_agv *ret, const char *fmt);
size_t			set_lmod(t_agv *ret, const char *fmt);
size_t			set_base(const char spec);

/* print_var.c */
size_t			print_var(size_t len, t_node *var, const int fd);

/* helpers.c */
const char		*skip_fmt(const char *s);
char			isSpecifier(char c);
char			isFlag(char c);
void			display_error(const char *s);
char			isModif(char c);

/* make_str.c */
void			*make_str(t_agv *fmt, va_list *ap);
void			*make_wstr(t_agv *fmt, va_list *ap);
void			*make_cstr(t_agv *fmt, va_list *ap);
void			*make_cwstr(t_agv *fmt, va_list *ap);
/* mkae_int.c */
void			*make_signed(t_agv *fmt, char type, va_list *ap);
void			*make_unsigned(t_agv *fmt, char type, va_list *ap);

/* make_dec.c */
char			*make_decimal(t_agv *fmt, char type, va_list *ap);

/* make_hex.c */
char			*make_hex(t_agv *fmt, t_byte caps, va_list *ap);
char			*make_fhex(t_agv *fmt, t_byte caps, va_list *ap);

/* make_utils.c */
char			*make_ptr(t_agv *fmt, va_list *ap);
char			*make_npstr(t_agv *fmt, va_list *ap);





#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

# include <get_next_line.h>

typedef unsigned char	t_byte;

typedef struct		s_node
{
	void			*data;
	size_t			d_size;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlnode
{
	void			*data;
	size_t			d_size;
	struct s_dlnode	*next;
	struct s_dlnode	*prev;
}					t_dlnode;

typedef struct		s_bnode
{
	void			*data;
	size_t			d_size;
	struct s_bnode	*left;
	struct s_bnode	*right;
}					t_bnode;

typedef struct		s_nbnode
{
	int				num;
	struct s_nbnode	*left;
	struct s_nbnode	*right;
}					t_nbnode;

typedef struct		s_snode
{
	void			*data;
	size_t			d_size;
	struct s_snode	*prev;
}					t_snode;

typedef struct		s_lst
{
	void			*head;
	void			*tail;
	size_t			len;
}					t_lst;

typedef struct		s_btree
{
	void			*root;
	void			*left;
	void			*right;
}					t_tree;

typedef struct		s_stack
{
	struct s_snode	*top;
	size_t			len;
}					t_stack;

typedef struct		s_array
{
	void			*data;
	size_t			d_size;
	size_t			len;
	size_t			bytes;
}					t_array;

void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);
void				*ft_memset(void *p, int c, size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *p, size_t size);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *p, int c, size_t n);
void				*ft_memrchr(const void *p, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_lltoa_base(long long n, int b);
char				*ft_uitoa_base(unsigned int n, int b);
char				*doubletoa(double n);
char				*ft_ftoa(float number);

char				*ft_hextoa(size_t n, size_t prec);
int					uctoutf8(const char *dest, wchar_t ch);
int					ft_hextoi(const char *hex);
char				*ft_ulltoa_base(unsigned long long n, int b);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
int					ft_ishex(int c);
int					ft_ishexstr(const char *hex);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isletter(char c1, char c2);

//	strings
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *small);
char				*ft_strnstr(const char *big, const char *small, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrev(const char *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strinsrt(const char *dst, size_t n, const char *src);
char				*get_next_word(const char *s, char **word);
char				**split_blnk(const char *str);
void				free_tab(char **ap);
char				*ft_chardup(const int ch);
char				*strtolower(char *str);
char				*printfstrdup(const char *s1);
char				*ft_strnchr(const char *s, int c, size_t len);

//	prints
size_t				ft_putchar(const char ch);
size_t				ft_putchar_fd(const char ch, int fd);
size_t				ft_putstr(char const *s);
size_t				ft_putstr_fd(char const *s, int fd);
size_t				putcstr(char const *s, size_t col);

// prints2
size_t				ft_putendl(char const *s);
size_t				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrnl(int n);
// prints3
size_t				ft_puthex(int c, size_t prec);
size_t				ft_puthexnl(int c, size_t prec);
void				set_color(int c);
void				ft_print_bits(unsigned char byte);

//	wchars
size_t				wchar_len(wchar_t ch);
size_t				wcharput(const wchar_t ch);
size_t				wstrput(wchar_t const *s);
size_t				wstrlen(const wchar_t *s);
wchar_t				*wstrnew(size_t len);

wchar_t				*wstrdup(const wchar_t *src);
wchar_t				*wchardup(const wchar_t src);
size_t				wcharput_fd(const wchar_t ch, const int fd);
size_t				wstrput_fd(const wchar_t *src, const int fd, size_t len);


t_byte				lst_addstr(t_lst *list, const char *name);
t_byte				lst_addarray(t_lst *list, t_array *add);

t_node				*ft_lstnew(void const *data, size_t d_size);
void				ft_lstdelone(t_node **curr, void (*bzero)(void *, size_t));
void				ft_lstdel(t_node **head, void (*bzero)(void *, size_t));
void				ft_lstadd(t_node **head, t_node *new);
void				ft_lstiter(t_node *head, void (*f)(t_node *node));
t_node				*ft_lstmap(t_node *head, t_node *(*f)(t_node *node));
void				ft_lstadd_back(t_node **head, t_node *new);
size_t				ft_lstlen(t_node *head);

t_dlnode			*dlnode_new(void const *data, size_t data_size);
t_byte				dlnode_del(t_dlnode **lst, void (*bzero)(void *, size_t));
size_t				dlinklst_del(t_dlnode **lst, void (*bzero)(void *, size_t));
void				dlnode_addnext(t_dlnode *curr, t_dlnode *add);
t_dlnode			*update_tail(t_dlnode *head);

t_dlnode			*split_dlinklst(t_dlnode **starting);
t_dlnode			*dlinklst_sort(t_dlnode **h, t_byte (*cmp)(void *, void *));
t_dlnode			*dlinklst_merge(t_dlnode *lst, t_dlnode *tmp,
					t_byte (*cmp)(void *, void *));

t_bnode				*bt_new(void const *data, size_t d_size);
t_bnode				*bt_lookup(t_bnode *tree, void const *data, size_t d_size);
t_bnode				*bt_insert(t_bnode *tree, void const *data, size_t d_size);
t_nbnode			*btn_new(const int n);
int					btn_lookup(t_nbnode *tree, const int n);
t_nbnode			*btn_insert(t_nbnode *tree, const int n);

t_snode				*snode_new(void const *data, size_t d_size);
t_snode				*stack_push(t_snode *top, t_snode *new);
t_snode				*stack_pop(t_snode *top);
t_snode				*stack_lookup(t_snode *top, t_snode *node);
void				snode_del(t_snode *node);
t_snode				*stack_last(t_snode	*top);
void				stack_del(t_snode *top);
size_t				stack_len(t_snode *top);

t_array				*array_new(size_t d_size, size_t len);
t_array				*array_resize(t_array *old, size_t new_size);
t_array				*array_clone(t_array *src);
void				array_destroy(t_array *curr);
void 				*array_look(t_array *curr, size_t index);
void				append_char(t_array **curr, size_t times, char ch);
void				cat_char(t_array **curr, size_t times, int ch);
void				append_atchar(t_array **c, size_t at, size_t tms, char ch);

int					ft_numlen(int n, int base);
int					ft_lnumlen(long n, int base);
int					ft_unumlen(unsigned int n, int base);
int					ft_ulnumlen(unsigned long n, int base);
char				get_sign(char *nbr);

#endif

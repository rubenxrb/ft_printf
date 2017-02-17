PRNTF	= ft_printf
MAIN	= main.c
NAME	= libftprintf.a

SRC		= ft_printf.c	\
		get_var.c		\
		read_var.c		\
		helpers.c		\
		print_var.c

ODIR	= ./obj/
SDIR	= ./srcs/
IDIR	= ./includes/
OBJ		= $(addprefix $(ODIR),$(SRC:.c=.o))

LDIR	= $(SDIR)libft/
LIB		= $(LDIR)libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ODIR) $(LIB) $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) main.c $(NAME) $(LIB) -I$(IDIR) -o $(PRNTF)

$(ODIR):
	mkdir -p $(ODIR)

$(LIB):
	make -C $(LDIR)

$(ODIR)%.o:$(SDIR)%.c
	$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $^

clean:
	make clean -C $(LDIR)
	rm -rf $(ODIR)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)
	rm -rf $(PRNTF)

make re: fclean $(NAME)

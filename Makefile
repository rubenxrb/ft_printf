PRNTF	= ft_printf
MAIN	= main.c
NAME = libftprintf.a

SRC =	ft_printf.c get_var.c read_var.c		\
		helpers.c print_var.c conv.c			\
		make_dec.c make_hex.c make_int.c		\
		make_str.c make_utils.c				

ODIR	= ./obj/
SDIR	= ./src/
IDIR	= -I./inc/
OBJ		= $(addprefix $(ODIR),$(SRC:.c=.o))

LDIR	= $(SDIR)libft/
INC		= -I$(LDIR)inc/ -I$(LDIR)src/get_next_line/inc
LIB		= $(LDIR)libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ODIR) $(LIB) $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) main.c $(NAME) $(IDIR) $(INC) -L$(LDIR) -lft -o $(PRNTF)

$(ODIR):
	mkdir -p $(ODIR)

$(LIB):
	make -C $(LDIR)

$(ODIR)%.o:$(SDIR)%.c
	$(CC) $(CFLAGS) $(INC) $(IDIR) -c -o $@ $^

clean:
	make clean -C $(LDIR)
	rm -rf $(ODIR)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)
	rm -rf $(PRNTF)

make re: fclean $(NAME)

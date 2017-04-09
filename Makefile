MAIN = main.c
NAME = libftprintf.a

CC = gcc
CFLGS = -Wall -Wextra -Werror

SDIR = ./src/
ODIR = ./obj/
IDIR = -I./inc/
LDIR = ./src/libft/
LINC = -I$(LDIR)inc/
GNL = $(LDIR)src/get_next_line/
IGNL = -I$(GNL)inc/
LBFT = $(LDIR)libft.a

SRCN =	ft_printf.c get_var.c read_var.c helpers.c	\
	print_var.c
SRC = $(addprefix $(SDIR),$(SRCN))
OBJ = $(addprefix $(ODIR),$(SRCN:.c=.o))

all: $(NAME)

test:
	@$(CC) $(CFLAGS) $(NAME) $(MAIN) $(IDIR) $(LINC) $(IGNL) -o test

$(NAME): src
	@ar rc $(NAME) $(OBJ)
	@printf "\x1b[32m[./libftprintf.a] <compiled>\n\x1b[0m"

src: lib mkobj $(OBJ)
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(CFLAGS) $(LINC) $(IDIR) -o $@ -c $<

lib:
	@make -s -C $(LDIR)

mkobj:
	@mkdir -p $(ODIR)

clean:
	@make -s -C $(LDIR) clean
	@$(RM) -rf $(ODIR)
	@echo "[ ./obj/ ] removed"

fclean: clean
	@make -s -C $(LDIR) fclean
	@$(RM) -rf $(NAME)
	@echo "[ ./libftprintf.a ] removed"

re: fclean all
.PHONY: all clean fclean re

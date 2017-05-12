PRNTF	= ft_printf
MAIN	= main.c
NAME = libftprintf.a

SRC =	ft_printf.c get_var.c read_var.c		\
		helpers.c print_var.c conv.c			\
		make_dec.c make_hex.c make_int.c		\
		make_str.c make_utils.c

LBS = 	memptrs.c memptrs2.c memptrs3.c		\
		convert.c convert2.c				\
		identifiers.c identifiers2.c		\
		strings.c strings2.c strings3.c		\
		strings4.c strings5.c strings6.c	\
		strings7.c wchar.c wchar2.c			\
		prints.c prints2.c prints3.c		\
		linkdlst.c linkdlst2.c dlinkdlst.c	\
		btree.c	nbtree.c misc.c				\
		stack.c stack2.c array.c			\
		dlinkdlst2.c lst.c

LBSN = $(addprefix ./src/libft/obj/,$(LBS:.c=.o))

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
	ar rc $(NAME) $(OBJ) $(LBSN)
#	gcc $(NAME) $(MAIN) $(INC) $(IDIR)

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

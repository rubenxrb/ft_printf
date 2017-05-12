LIB = libft.a

CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Werror -Wextra
INC = -Iinc -Isrc/get_next_line/inc

ODIR = ./obj/
SDIR = ./src/

GNLSRC = $(addprefix $(SDIR),get_next_line/src/)
GNLS = get_next_line.c
GNLN = $(addprefix $(GNLSRC),$(GNLS))
GNLO = $(addprefix $(ODIR)get_next_line/,$(GNLS:.c=.o))
SRCN = 	memptrs.c memptrs2.c memptrs3.c	\
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

OBJN =	$(SRCN:.c=.o)
SRC =	$(addprefix $(SDIR),$(SRCN))
OBJ =	$(addprefix $(ODIR),$(OBJN))

all: $(LIB)

$(LIB): src adds
	@ar rc $(LIB) $(GNLO)
	@printf "\x1b[32m[./libft.a] <compiled>\n\x1b[0m"

src: mkobj $(OBJ) comp
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkobj:
	@mkdir -p $(ODIR)

comp:
	@ar rc $(LIB) $(OBJ)

adds: mkadd $(GNLO)

$(GNLO):$(GNLN)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkadd:
	@mkdir -p $(addprefix $(ODIR),get_next_line/)

clean:
	@$(RM) -rf $(ODIR)
	@$(RM) -rf $(ADDO)

fclean: clean
	@$(RM) -rf $(LIB)
	@printf "\x1b[31m[./libft.a] <removed>\n\x1b[0m"

re: fclean all
.PHONY: all clean fclean re

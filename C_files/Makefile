NAME = a.out

SRC = ft_nbr_strlen.c\
      ft_unsigned_putnbr.c\
      ft_chr_str.c\
      ft_putnbr_base.c\
      ft_putnbr_ptr.c\
      ft_printf.c\
      main_text.c
#      ft_convert_base2.c\
#     ft_convert_base.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

CFLAGS = -Wall -Wextra

$(NAME): $(OBJ)
	cc $(CFLAGS) $^ -o $(NAME)
	
	
clean:
	rm -f $(OBJ)

bug: $(SRC)
	cc $(CFLAGS) $^ -o $(NAME) -g

reel: $(OBJ)
	ar rsc printf.a $?
.PHONY: bug clean reel

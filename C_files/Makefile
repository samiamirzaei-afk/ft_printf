NAME = a.out

SRC = ft_nbr.c\
      ft_chr_str.c\
      ft_convert_base2.c\
      ft_convert_base.c\
      ft_putnbr_base.c\
      print_str.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	cc $(CFLAGS) $^ -o $(NAME)

bug: $(SRC)
	cc $(CFLAGS) $^ -o $(NAME) -g
.PHONY: bug

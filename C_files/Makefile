NAME = a.out

SRC = ft_nbr_strlen.c\
      ft_chr_str.c\
      ft_putnbr_base.c\
      ft_putnbr_ptr.c\
      print_str.c
#      ft_convert_base2.c\
#     ft_convert_base.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	cc $(CFLAGS) $^ -o $(NAME)
	
	
clean:
	rm -f $(OBJ)

bug: $(SRC)
	cc $(CFLAGS) $^ -o $(NAME) -g
.PHONY: bug clean

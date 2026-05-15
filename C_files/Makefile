SRC = ft_nbr_strlen.c\
      ft_unsigned_putnbr.c\
      ft_chr_str.c\
      ft_putnbr_base.c\
      ft_putnbr_ptr.c\
      ft_printf.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $?
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bug: $(SRC)
	cc $(CFLAGS) main_text.c $^  -g


.PHONY: bug clean fclean re

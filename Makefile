SRC = ft_nbr_strlen.c\
      ft_unsigned_putnbr.c\
      ft_chr_str.c\
      ft_putnbr_base.c\
      ft_putnbr_ptr.c\
      ft_printf.c

SRC_DIR = src/

OBJ = $(addprefix $(SRC_DIR),$(SRC:.c=.o))
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bug: $(addprefix $(SRC_DIR), $(SRC))
	cc src/.main_text.c $^ -g

cbug: 
	$(RM) a.out
.PHONY: bug cbug clean fclean re

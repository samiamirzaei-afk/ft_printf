#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

/*	ft_nbr_strlen*/
int	ft_putnbr(int nb);
size_t ft_strlen(const char *str);

/*	ft_nbr_strlen*/
int	ft_unsigned_putnbr(unsigned nb);

/* ft_chr_str*/
int     ft_putstr(char *s);
int     ft_putchar(char car);

/*ft_putnbr_base*/
int    ft_show(int *result, int *result_i, char *base, int count);
int	ft_putnbr_base(void *ptr, char *base);
int     ft_convert(unsigned long nbr, int len, char *base, int count);

/*ft_putnbr_ptr.c*/
int	ft_putnbr_ptr(void *ptr, char *base);

/*int     ft_print*/
int     ft_printf(const char *str, ...);

#endif

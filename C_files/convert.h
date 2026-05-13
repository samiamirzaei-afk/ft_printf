#ifndef CONVERT_H
#define CONVERT_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	ft_nbr_strlen*/
int	ft_putnbr(int nb);
size_t ft_strlen(const char *str);

/* ft_chr_str*/
int     ft_putstr(char *s);
int     ft_putchar(char car);

/*ft_putnbr_base*/
int    ft_show(int *result, int *result_i, char *base, int count);
int	ft_putnbr_base(void *ptr, char *base);
int     ft_convert(unsigned long nbr, int len, char *base, int count);
/*ft_putnbr_ptr.c*/
int	ft_putnbr_ptr(void *ptr, char *base);


#endif

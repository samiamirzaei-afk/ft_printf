#ifndef CONVERT_H
#define CONVERT_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//	ft_nbr
int	ft_putnbr(int nb);

// ft_chr_str
int     ft_putstr(char *s);
int     ft_putchar(char car);


int ft_power(int base, int power);

int     ft_convert(unsigned long nbr, int len, char *base);
void    ft_show(int *result, int *result_i, char *base);
int	ft_putnbr_base(void *ptr, char *base);

int ft_dec_conversion(int number, size_t number_length, char *base);

size_t ft_strlen(const char *str);

char *ft_dec_to_base(int number, char *base);

int ft_valid(char *base);

#endif

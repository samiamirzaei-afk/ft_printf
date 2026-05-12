#ifndef CONVERT_H
#define CONVERT_H

int ft_power(int base, int power);

int ft_dec_conversion(int number, size_t number_length, char *base);

size_t ft_strlen(const char *str);

char *ft_dec_to_base(int number, char *base);

int ft_valid(char *base);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:12:10 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:46:54 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>

/* Hexadecimal base constants */
# define HEX_LO "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

/*ft_nbr_strlen*/
int		ft_putnbr(int nb);
size_t	ft_strlen(const char *str);

/*ft_unsigned_putnbr*/
int		ft_unsigned_putnbr(unsigned int nb);

/*ft_chr_str*/
int		ft_putstr(char *s);
int		ft_putchar(char car);

/*ft_putnbr_base*/
int		ft_show(short *result, int *result_i, char *base, int count);
int		ft_putnbr_base(unsigned int ptr, char *base);
int		ft_convert(unsigned int nbr, int len, char *base, int count);

/*ft_putnbr_ptr.c*/
int		ft_putnbr_ptr(void *ptr, char *base);
int		ft_convert_ptr(unsigned long nbr, int len, char *base, int count);
/*int     ft_print*/
int		ft_printf(const char *str, ...);

#endif

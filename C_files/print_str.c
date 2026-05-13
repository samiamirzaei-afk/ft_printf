/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:54:08 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/13 12:57:33 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "convert.h"


int	print_str(const char *str, ...)
{
	va_list ap;
	int count;

	count = 0;	
	va_start(ap, str);
	while (*str)
	{	
		if(*str == '%' && *(str + 1) == 'c')
		{
			count += ft_putchar((char)va_arg(ap, int));
			str += 2;
		}
		if(*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
		{
			count += ft_putnbr(va_arg(ap, int));
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 's')
		{
			count += ft_putstr(va_arg(ap, char *));
			str += 2;
		}
		if(*str == '%' && *(str + 1) == '%')
		{
			count += ft_putchar('%');
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 'p')
		{
			count +=ft_putnbr_ptr(va_arg(ap, void *), "0123456789abcdef");
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 'x')
		{
			count +=ft_putnbr_base(va_arg(ap, void *), "0123456789abcdef");
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 'X')
		{
			count += ft_putnbr_base(va_arg(ap, void *), "0123456789ABCDEF");
			str += 2;
		}
		while(*str != '%' && *str)
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(ap)
	return(count);
}


int	main()
{
	int error;
	int hex;

	hex = 42424242;	
//	error = print_str("this IS a good %X %x %p string my bro ", 1000, 123456789, &error);
//	error = printf("\n ft_count:%d\n", error);
//	error = printf("this IS a good %X %x %p string my bro \n", 1000, 123456789, &error);
//	error = printf("og_count:%d\n", error);
	error = print_str("this IS a good '%X' string my bro \n", hex);
	error = printf("ft_count:%d\n", error);
	   error = printf("this IS a good '%X' string my bro \n", hex);
	error = printf("og_count:%d\n", error);
	return (error);
}


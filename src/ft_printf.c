/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:54:08 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:09:02 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_finder2(const char **str, va_list ap, int *count, char *base)
{
	if (**str == '%' && (*str)[1] == 'X')
	{
		*count += ft_putnbr_base(va_arg(ap, unsigned int), base);
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == 'c')
	{
		*count += ft_putchar((char)va_arg(ap, int));
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == 's')
	{
		*count += ft_putstr(va_arg(ap, char *));
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == '%')
	{
		*count += ft_putchar('%');
		*str += 2;
	}
}

void	format_finder(const char **str, va_list ap, int *count, char *base)
{
	if (**str == '%' && ((*str)[1] == 'd' || (*str)[1] == 'i'))
	{
		*count += ft_putnbr(va_arg(ap, int));
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == 'p')
	{
		*count += ft_putnbr_ptr(va_arg(ap, void *), base);
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == 'x')
	{
		*count += ft_putnbr_base(va_arg(ap, unsigned int), base);
		*str += 2;
	}
	if (**str == '%' && (*str)[1] == 'u')
	{
		*count += ft_unsigned_putnbr(va_arg(ap, unsigned int));
		*str += 2;
	}
	format_finder2(str, ap, count, "0123456789ABCDEF");
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	if (str == NULL)
		return (-1);
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			format_finder(&str, ap, &count, "0123456789abcdef");
		}
		while (*str != '%' && *str)
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(ap);
	return (count);
}

/*
int	ft_printf(const char *str, ...)
{
	va_list ap;
	int count;

	count = 0;	
	va_start(ap, str);
while (*str)
{	
	if(*str == '%' && *(str + 1) == 'u')
	{
		count += ft_unsigned_putnbr(va_arg(ap, unsigned int));
		str += 2;
	}
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
	va_end(ap);
	return(count);
}
*/
/*
int	main()
{
	int error;
	int hex;
	char *null = NULL;

	hex = 42424242;
	hex += 1;
	
error = print_str(" %X %x %p string my bro ", 1000, 123456789, &error);
	error = printf("\n ft_count:%d\n", error);
error = printf(" %X %x %p string my bro \n", 1000, 123456789, &error);
	error = printf("og_count:%d\n\n", error);
	error = print_str("this IS a good %s string my bro \n", null);
	error = printf("ft_count:%d\n", error);
	   error = printf("this IS a good %s string my bro \n", null);
	error = printf("og_count:%d\n", error);

	error = print_str("this IS a good %s string my bro \n", null);
	error = printf("ft_count:%d\n", error);
	   error = printf("this IS a good %s string my bro \n", null);
	error = printf("og_count:%d\n", error);
	return (error);
}
*/

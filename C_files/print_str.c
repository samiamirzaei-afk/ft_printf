#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_putnbr_base.c"


static int	ft_max_min_check(int nb, int *count)
{
	*count = 0;
	if (nb == 2147483647)
		return (write(1, "2147483647", 10));
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	return (-1);
}

int	ft_putnbr(int nb)
{
	int	i;
	int 	count;
	char	itoa[12];

	if ((count = ft_max_min_check(nb, &count)) != -1)
		return (count);
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb *= -1;
	}
	itoa[0] = '\0';
	i = 1;
	while (nb > 9)
	{
		itoa[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	itoa[i] = nb + '0';
	while (itoa[i--] != '\0')
		count += write(1, &itoa[i], 1);
	return (count);
}

int	ft_putstr(char *s)
{
	int len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}


int	ft_putchar(char car)
{	
		return (write(1, &car, 1));
}


int	print_str(const char *str, ...)
{
	va_list ap;
	void *result;
	int count;
	
	va_start(ap, str);
	while (*str)
	{	
		if(*str == '%' && *(str + 1) == 'c')
		{
			count += ft_putchar((char)va_arg(ap, int));
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 'd')
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
			ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
			str += 2;
		}
		while(*str != '%' && *str)
		{
			count += ft_putchar(*str);
			str++;
		}

	}
	return(count);
}


int	main(int argc, char **argv)
{
	if (argc < 1)
	{
		write(1, "please provide an argument\n", 27);
		return (1);
	}
	int error;
//	error = print_nbr(2, 12345, 6789);
	error = print_str("this is a good %s %s gsg %c %p string my bro ","000", "000", 'x', &error);
	error = printf("\n ft_count:%d\n", error);
	error = printf("this is a good %s %s gsg %c %p string my bro \n","000", "000", 'x', &error);
	error = printf("this is a good %s %s gsg %c %p string my bro \n","000", "000", 'x', &error);
	error = printf("this is a good %s %s gsg %c %p string my bro \n","000", "000", 'x', &error);
	error = printf("og_count:%d\n", error);
	return (error);

}


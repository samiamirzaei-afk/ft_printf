#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


static int	ft_max_min_check(int nb)
{
	if (nb == 2147483647)
	{
		write(1, "2147483647", 10);
		return (1);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	itoa[12];

	if (ft_max_min_check(nb) == 1)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
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
	while (itoa[i] != '\0')
	{
		write(1, &itoa[i], 1);
		i--;
	}
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

int	print_nbr(int n, ...)
{
	int i;
	va_list ap;
	int result;
	
	i = 0;
	result = 0;
	va_start(ap, n);
	while (i < n)
	{
		result = (int)va_arg(ap, int);
		printf("%d\n", result);
		i++;

	}
	return(1);
}


int	print_str(const char *str, ...)
{
	va_list ap;
	void *result;
	
	va_start(ap, str);
	while (*str)
	{	
		if(*str == '%' && *(str + 1) == 'c')
		{
				ft_putchar((char)va_arg(ap, int));
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 'd')
		{
				ft_putnbr(va_arg(ap, int));
			str += 2;
		}
		if(*str == '%' && *(str + 1) == 's')
		{
				ft_putstr(va_arg(ap, char *));
			str += 2;
		}
		while(*str != '%' && *str)
		{
			ft_putchar(*str);
			str++;
		}

	}
	return(1);
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
	error = print_str("this is a good %s%sgsg%c%c string my bro ","000", "000", 'x', 'x', 'x');
//	error = printf("this is a good string my bro %s", "also good string");
	return (error);

}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:08:20 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:44:04 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_max_min_neg_check(int *nb, int *count)
{
	if (*nb == 2147483647)
		return ((*count = write(1, "2147483647", 10)));
	if (*nb == -2147483648)
		return ((*count = write(1, "-2147483648", 11)));
	if (*nb < 0)
	{
		*count = write(1, "-", 1);
		if (*count == -1)
			return (-1);
		*nb *= -1;
	}
	return (1);
}

static int	ft_show_nbr(int *count, int *i, char *itoa)
{
	int	result;

	while (itoa[*i] != '\0')
	{
		result = write(1, &itoa[(*i)--], 1);
		if (result == -1)
		return (-1);
		*count += result;
	}
	return (*count);
}

int	ft_putnbr(int nb)
{
	int		i;
	int		count;
	char	itoa[12];

	count = 0;
	if ((ft_max_min_neg_check(&nb, &count)) != 1)
		return (count);
	itoa[0] = '\0';
	i = 1;
	while (nb > 9)
	{
		itoa[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	itoa[i] = nb + '0';
	if (ft_show_nbr(&count, &i, itoa) == -1)
		return (-1);
	return (count);
}
/*
int	main(void)
{
	int	num;

	num = 12345;
	ft_putnbr(num);
}
*/

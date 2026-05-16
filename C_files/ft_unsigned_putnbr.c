/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:09:34 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:09:44 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	int		i;
	int		count;
	char	itoa[12];
	int		result;

	count = 0;
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
		result = write(1, &itoa[i--], 1);
		if (result == -1)
			return (-1);
		count += result;
	}
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

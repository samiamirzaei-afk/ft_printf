/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:30:34 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:09:22 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_ptr(unsigned long nbr, int len, char *base, int count)
{
	int	temp[21];
	int	i;

	i = 1;
	temp[0] = -1;
	while (nbr >= (unsigned long)len)
	{
		temp[i] = nbr % len;
		nbr /= len;
		i++;
	}
	temp[i] = nbr;
	count = ft_show(temp, &i, base, count);
	return (count);
}

int	ft_putnbr_ptr(void *ptr, char *base)
{
	int				i;
	unsigned long	nbr;
	int				count;

	count = 0;
	if (ptr == NULL)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	nbr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	i = 0;
	while (base[i])
		i++;
	return (ft_convert_ptr(nbr, i, base, count));
}

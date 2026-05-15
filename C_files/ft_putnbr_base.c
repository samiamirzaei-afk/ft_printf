/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:30:34 by ammirzae          #+#    #+#             */
/*   Updated: 2026/02/13 11:40:12 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show(int *result, int *result_i, char *base, int count)
{
	char	temp;
	int write_check;

	write_check = 0;
	while (result[*result_i] != -1)
	{
		temp = base[result[*result_i]];
		if((write_check = write(1, &temp, 1)) == -1)
			return (-1);
		count += write_check;
		*result_i = *result_i - 1;
	}
	return (count);
}

int	ft_convert(unsigned long nbr, int len, char *base, int count)
{
	int		temp[21];
	int		i;

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
	return(count);
}

int	ft_putnbr_base(void *ptr, char *base)
{
	int	i;
	unsigned long nbr;
	int count;

	nbr = (unsigned long)ptr;
	count = 0;
	i = 0;
	while (base[i])
		i++;
	return(ft_convert(nbr, i, base, count));
}

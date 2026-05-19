/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:30:34 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/16 16:09:15 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show(short *buffer, int *buffer_len, char *base, int count)
{
	int		write_check;

	write_check = 0;
	while (buffer[*buffer_len] != -1)
	{
		write_check = write(1, &base[buffer[*buffer_len]], 1);
		if (write_check == -1)
			return (-1);
		count += write_check;
		(*buffer_len) -= 1;
	}
	return (count);
}

/*
int	ft_show(int *buffer, int *buffer_len, char *base, int count)
{
	char	temp;
	int		write_check;

	write_check = 0;
	while (buffer[*buffer_len] != -1)
	{
		temp = base[buffer[*buffer_len]];
		write_check = write(1, &temp, 1);
		if (write_check == -1)
			return (-1);
		count += write_check;
		*buffer_len = *buffer_len - 1;
	}
	return (count);
}
*/


int	ft_convert(unsigned int nbr, int base_len, char *base, int count)
{
	short	digit_buffer[21];
	int	i;

	i = 1;
	digit_buffer[0] = -1;
	while (nbr >= (unsigned int)base_len)
	{
		digit_buffer[i] = nbr % base_len;
		nbr /= base_len;
		i++;
	}
	digit_buffer[i] = nbr;
	count = ft_show(digit_buffer, &i, base, count);
	return (count);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				base_len;
	int				count;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	return (ft_convert(nbr, base_len, base, count));
}

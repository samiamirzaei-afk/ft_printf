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


#include "convert.h"

int	ft_putnbr_ptr(void *ptr, char *base)
{
	int	i;
	unsigned long nbr;
	int count;

	nbr = (unsigned long)ptr;
	count = 0;
	if((count = write(1, "0x", 2)) == -1)
		return(-1);
	i = 0;
	while (base[i])
		i++;
	return(ft_convert(nbr, i, base, count));
}

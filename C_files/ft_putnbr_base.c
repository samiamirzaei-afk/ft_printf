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
/*
#include <stdio.h>
#include <stdlib.h>
*/
#include <unistd.h>

int	ft_error_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i;
		while (base[i] != base[j + 1] && base[i] != '+' && base[i] != '-'
			&& base[j] != '\0')
		{
			j++;
		}
		if (base[i] == base[j + 1] || base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

/*	* * * * HELPER FUNCTION * * * *		*/

void	ft_show(int *result, int *result_i, char *base)
{
	char	temp;

	while (result[*result_i] != -1)
	{
		temp = base[result[*result_i]];
		write(1, &temp, 1);
		*result_i = *result_i - 1;
	}
}

void	ft_convert(int nbr, int len, char *base)
{
	int		temp[20];
	int		i;
	long	nbrl;

	nbrl = nbr;
	i = 1;
	temp[0] = -1;
	if (nbrl < 0)
	{
		nbrl = nbrl * -1;
		write(1, "-", 1);
	}
	while (nbrl >= len)
	{
		temp[i] = nbrl % len;
		nbrl /= len;
		i++;
	}
	temp[i] = nbrl;
	ft_show(temp, &i, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (ft_error_check(base) == -1 || i <= 1)
		return ;
	ft_convert(nbr, i, base);
}
/*
int	main(void)
{
	int	i;
	int	k;
	
	k = 2147483600;
	for(i = -2147483600; i != k; i--)
	{  
		ft_putnbr_base(i, "0123456789abcdef");
		write(1, "\n", 1);
	}
//	ft_putnbr_base(atoi(argv[1]), argv[2]);
}
*/


/*
int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		printf("please provide an argument");
		return (1);
	}
	i = -2147483648;
	ft_putnbr_base(i, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(atoi(argv[1]), argv[2]);
}
*/

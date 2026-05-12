#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if(!str)
		return(0);
	i = 0;
	while(str[i] != '\0')
		i++;
	return(i); 
}

int	ft_atoi(char *string)       
{
	int i;
	int negative_count;
	int negative;
	int number;
	i = 0;
	negative = 0;
	negative_count = 0;
	number = 0;
	while(string[i] >= 2 && string[i] <= 32)
		i++;
	while(string[i] == '-' || string[i] == '+')
	{
		if(string[i] == '-')
			negative_count++;
		i++;	
	}
	if(negative_count % 2 == 1)
		negative = 1;
	while(string[i] <= '9' && string[i] >= '0')
	{
		number = number + (string[i] - 48);
		number = number * 10;
		i++;
	}
	number = (number / 10);
	if(negative == 1)
		number = number * -1;
	printf("\n***atoied nbr should be: '%d'\n", number);
	return(number);
}	

char	*ft_copy_malloc(const char *source)
{
	int i;
	char *copy;
	size_t size;
	
	if(source == NULL)
	{
		printf("\n***MALLOC FAILLED***, null string!\n");
		return(NULL);
	}
	size = ft_strlen(source);
	copy = malloc ((size + 1) * sizeof(char));
	if(copy == NULL)
	{
		printf("\n***MALLOC FAILLED***, Null return!\n");
		return(NULL);
	}
	i = 0;
	while (source[i] != '\0')
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return(copy);
}


char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *nbr_malloc;
	char *base_from_malloc;
	char *base_to_malloc;

	size_t size;
	int int_nbr;
	char *result;
	int temp;
	temp = ft_valid(base_from);
	int_nbr = ft_valid(base_to);
	if(temp == -1 || int_nbr == -1)
	{
		return(NULL);
	}

	size = ft_strlen(nbr);
	nbr_malloc = ft_copy_malloc(nbr);
	base_from_malloc = ft_copy_malloc(base_from);
	base_to_malloc = ft_copy_malloc(base_to);

//	printf("nbr: '%s'\nbase_from: '%s'\nbase_to: '%s'\n", nbr_malloc, base_from_malloc, base_to_malloc);
	
	temp = ft_atoi(nbr_malloc);
	int_nbr = ft_dec_conversion(temp, size,  base_from_malloc);
	result = ft_dec_to_base(int_nbr, base_to);

	free(nbr_malloc);
	free(base_from_malloc);
	free(base_to_malloc);
	return(result);
}

/*
int	main(int argc, char ** argv) // 4B0H	0ABC456GHI	0123456789 ==> 4208
{
	if(argc != 4)
	{
		printf("please provide a number, source base and convert base as arguments\n");
		return(1);
	}

	char *result;

	result = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("after conversion: %s\n", result);
	free(result);
	return(0);
}*/

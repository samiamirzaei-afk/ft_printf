#include "convert.h"
int	ft_valid(char* base)
{
	int i;
	int j;

	j = 0;

	while(base[j] != '\0')
	{
		i = j + 1;
		while(base[i] != '\0')
		{
			if(base[j] == base[i])
			{
				printf("invalid base\n");
				return(-1);
			}
			i++;
		}
		j++;
	}
	if(j < 2)
	{
		printf("invalid base\n");
			return(-1);
	}
	return(0);
}

int	ft_power(int base, int power)
{
	int answer;

	answer = 1;
	if(power == 1)
		return(base);
	if (power == 0)
		return(1);
	while(power != 0)
	{
		answer = answer * base;
			power--;
	}
	return(answer);

}



int	ft_dec_conversion(int number, size_t number_length, char *base)
{
	int i;
	int j;
	int k;
	int *array_number;
	int temp;
	int number_dec;
	int negative;

	i = 1;
	k = 1;
	j = 0;
	number_dec = 0;
	negative = 0;
	if(number < 0)
	{
		number = number * -1;
		negative = 1;
	
	}
	temp = number;
	while(base[i] != '\0')
		i++;
/*	if(i < 1)
	{
		printf("Invalid base");
		return(-1);
	}*/
	if(i == 10)
	{
//		printf("no ft_dec_conversion needed!\n");
		return(number);
	}

	array_number = malloc ((number_length + 1) * sizeof(int));
	array_number[0] = -1;
	while(temp > 9)
	{
		array_number[k] = temp % 10;
		temp = temp / 10;
		k++;
	}

	array_number[k] = temp;
	while(array_number[k] != -1)
	{
		temp = array_number[k] * ft_power(i, k -1); 
		number_dec = number_dec + temp;
		k--;

	}
	if(negative == 1)
		number = number * -1;
	printf("number_dec: '%d'\n", number_dec);

	return(number_dec);
}


char	*ft_array_to_int(int *array, int array_size, char *base, int base_length)
{
	int i;
	char *final_string;

	i = 0;
	array_size--;
	final_string = malloc((array_size) * (sizeof(char)));
	if(final_string == NULL)
	{
		printf("***MALLOC FAIL! ft_array_to_int***");
		return(NULL);
	}
	while(array[array_size] != -1)
	{
		final_string[i] = base[array[array_size]];
		array_size--;
		i++;
	}
	printf("final_string: '%s'\n", final_string);
	return(final_string);
}


char	*ft_dec_to_base(int number, char *base)
{
	int i;
	int mod_store_length;
	int div;
	int mod;
	int base_length;
	int *mod_store;
	char *final;

	i = 1;
	div = number;
	base_length = (int)ft_strlen(base);
	mod_store = malloc(32 * sizeof(int)); 
	mod_store[0] = -1;
printf("div satrt:'%d'\n", div);
	while(div > 0)
	{
		mod = div % base_length;
		div = div / base_length;
		mod_store[i] = mod;
		i++;
		printf("\ndiv: '%d', mod: '%d'\n base_length: '%d'\n", div, mod, base_length);
	}
	mod_store[i] = '\0';
	mod_store_length = i;
	while(i != -1)
	{	
	printf("mod_store:");
	printf(" %d,", mod_store[i]);
	printf("\n");
		i--;
	}
	
	final = ft_array_to_int(mod_store, mod_store_length, base, base_length);
	free(mod_store);
	return(final);


}


/*
int	main(int argc, char **argv)
{

	if(argc != 4)
	{
		printf("please provide only a number, the base of that number and a base to convert it to\n");
		return(1);
	}



	if(argc != 3)		// FOR POWER TESTING!!
	{
		printf("please give a number and its power");
			return(1);
	}



	int number;
	int number_dec = 0;
	int size;
	char *final_answer;
	size = strlen(argv[1]);

	number = atoi(argv[1]) * -1;
	number_dec = ft_dec_conversion(number, size, argv[2]);
	final_answer = ft_dec_to_base(number_dec, argv[3]);
	printf("final answer: '%s'",final_answer);
	free(final_answer);

		
		***** FOR POWER TESTING!
	int base;
	int power;
	int result;
	base = atoi(argv[1]);
	power = atoi(argv[2]);
	result = ft_power(base, power);
	printf("result: '%d'", result);

}

*/

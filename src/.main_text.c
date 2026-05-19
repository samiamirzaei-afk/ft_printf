#include "ft_printf.h"
#include <limits.h>

int    main(void)
{
    char    name[] = "Dmytro";
    int        count = 0;
    int     rcount = 0;
    int        m;
    int        o;
	
    o = 1;
    m = 1;
    ft_printf("my   ft: %d\n", o);
    printf("real ft: %d\n", m);

//	m = printf(NULL);
//	o = ft_printf(NULL);
//	printf("og: %d\n", m);
//	printf("ft: %d\n", o);
    ft_printf("\n\n");
    
m = ft_printf("ft: %x ", UINT_MAX);
o = printf("OG: %x ", UINT_MAX);
	printf("og: %d\n", m);
	printf("ft: %d\n", o);
    ft_printf("\n\n");
m = ft_printf("ft: %x ", 0);
o = printf("OG: %x ", 0);
	printf("og: %d\n", m);
	printf("ft: %d\n", o);


    char *null = NULL;
    count = ft_printf(" NULL %s NULL \n", null);
    rcount = printf(" NULL %s NULL \n", null);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    unsigned int num;

    for(num = 1000; num != 1010 ; num++)
    {
	count = ft_printf("[%i] [%i] [%i]\n", num, num + 1, num + 2);
    	rcount = printf("[%i] [%i] [%i]\n", num, num + 1, num + 2);
    	ft_printf("my   ft: %d\n", count);
    	printf("real ft: %d\n\n", rcount);
    }

    rcount = printf("NULL");
    count = ft_printf("NULL");
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);


    count = ft_printf("Hi, my name is [%s].\n", name);
    rcount = printf("Hi, my name is [%s].\n", name);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%c]\n", 'D');
    rcount = printf("[%c]\n", 'D');
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%p]\n", NULL);
    rcount = printf("[%p]\n", NULL);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);
    count = ft_printf("[%p]\n", name);
    rcount = printf("[%p]\n", name);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%d]\n", -2486);
    rcount = printf("[%d]\n", -2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%d]\n", -2147483648);
    rcount = printf("[%ld]\n", -2147483648);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%i]\n", -2486);
    rcount = printf("[%i]\n", -2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);


/*  	 * 	*	*	*/

    count = ft_printf("[%u]\n", 2486);
    rcount = printf("[%u]\n", 2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%x]\n", 244586);
    rcount = printf("[%x]\n", 244586);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%X]\n", 244586);
    rcount = printf("[%X]\n", 244586);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("My test: [%%]\n");
    rcount = printf("My test: [%%]\n");
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("My test: [%%+]\n");
    ft_printf("my   ft: %d\n\n", count);

    return (0);
}

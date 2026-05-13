int    main(void)
{
    char    *name = "Dmytro";
    int        count = 0;
    int     rcount = 0;
    int        m;
    int        o;

    o = ft_printf(NULL);
    ft_printf("my   ft: %d\n", o);
    m = printf(NULL);
    printf("real ft: %d\n", m);

    ft_printf("\n");

    count = ft_printf(" NULL %s NULL \n", (char *)NULL);
    rcount = printf(" NULL %s NULL \n", (char *)NULL);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

//    count = ft_printf("my   ft: [%y]\n");
//    rcount = printf("real ft: [%y]\n");
//    ft_printf("my   ft: %d\n", count);
//    printf("real ft: %d\n\n", rcount);

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

    count = ft_printf("[%u]\n", 2486);
    rcount = printf("[%u]\n", 2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%x]\n", 2486);
    rcount = printf("[%x]\n", 2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("[%X]\n", 2486);
    rcount = printf("[%X]\n", 2486);
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("My test: [%%]\n");
    rcount = printf("My test: [%%]\n");
    ft_printf("my   ft: %d\n", count);
    printf("real ft: %d\n\n", rcount);

    count = ft_printf("My test: [%+]\n");
    ft_printf("my   ft: %d\n\n", count);

    return (0);
}

#include "ft_printf.h"



int     ft_putstr(char *s)
{
        int len;

        len = 0;
        if (s == NULL)
                return (write(1, "(null)", 6));
        len = ft_strlen(s);
        len = write(1, &s[0], len);
        return (len);
}


int     ft_putchar(char car)
{
                return (write(1, &car, 1));
}
   

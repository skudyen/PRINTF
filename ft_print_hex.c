#include "ft_printf.h"

int ft_print_hex(unsigned long nb)
{
    unsigned long   cnt;
    char    c;

    cnt = 0;
    if (nb >= 16)
        cnt += ft_print_hex(nb / 16);
    nb %= 16;
    if (nb < 10)
        c = nb + '0';
    else
        c = nb - 10 + 'a';
    cnt += ft_print_c(c);
    return (cnt);
}

int ft_print_upperhex(unsigned int nb)
{
    unsigned int    cnt;
    char            c;

    cnt = 0;
    if (nb >= 16)
        cnt += ft_print_upperhex(nb / 16);
    nb %= 16;
    if (nb < 10)
        c = nb + '0';
    else
        c = nb - 10 + 'A';
    cnt += ft_print_c(c);
    return (cnt);
}

int ft_print_ptr(void *ptr)
{
    int             cnt;
    unsigned long   pointer;

    cnt = 0;
    pointer = (unsigned long)ptr;
    if (ptr == NULL)
    {
        write (1, "(nil)", 5);
        return (5);
    }
    cnt += write(1, "0x", 2);
    cnt += ft_print_hex(pointer);
    return (cnt);
}
//-----------------------------------------------------//
// #include <stdio.h>

// int main()
// {
//     unsigned long a = 20000;
//     printf("%lu\n", ft_print_hex(a));

//     unsigned long c = 20000;
//     printf("%lu\n", ft_print_upperhex(c));

//     int b = 42;
//     void    *ptr = &b;

//     printf("Pointer address :");
//     ft_print_ptr(ptr);
//     printf ("\n");
    
//     printf("NULL Pointer :");
//     ft_print_ptr(NULL);
//     printf ("\n");
    

// }

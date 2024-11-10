#include "ft_printf.h"

int ft_print_unsigned_int(unsigned int nb)
{
    unsigned int    cnt;
    char        c;

    cnt = 0;
    if (nb > 9)
        cnt += ft_print_unsigned_int(nb / 10);
    c = (nb % 10) + '0';
    cnt += ft_print_c(c);
    return (cnt);
}

int ft_print_int(int nb)
{
    int cnt;
    char    c;

    cnt = 0;
    if(nb == -2147483648)
    {
        cnt += write(1, "-2147483648", 11);
        return (cnt);
    }
    if(nb < 0)
    {
        cnt += ft_print_c('-');
        nb = -nb;
    }
    if(nb > 9)
    {
        cnt += ft_print_int(nb / 10);
    }
    c = (nb % 10) + '0';
    cnt += ft_print_c(c);
    return (cnt);
}

// #include <stdio.h>

// int main()
// {
//     unsigned int a = 2147483647;
//     printf("%u\n", ft_print_unsigned_int(a));
//     unsigned int aa = -2147483647;
//     printf("%u\n", ft_print_unsigned_int(aa));
//     unsigned int ab = 21647;
//     printf("%u\n", ft_print_unsigned_int(ab));
//     int b = 1000;
//     printf("%d\n", ft_print_int(b));
//     int c = -2147483648;
//     printf("%d\n", ft_print_int(c));
//     int d = -21464;
//     printf("%d\n", ft_print_int(d));
// }
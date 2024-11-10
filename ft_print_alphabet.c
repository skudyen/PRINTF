#include "ft_printf.h"

int ft_print_c(char c)
{
    write (1, &c, 1);
    return (1);
}

int ft_print_str(char *s)
{
    int cnt;

    cnt = 0;
    while (!s)
    {
        ft_print_str("(null)");
        return (6);
    }
    while (s[cnt])
    {
        ft_print_c(s[cnt]);
        cnt++;
    }
    return (cnt);
}

// #include <stdio.h>
// int main()
// {
//     char A[] = "Oasis";
//     char *null_ptr = NULL;

//     printf("%d\n", ft_print_str(A)); 
//     printf("%d\n", ft_print_str(null_ptr)); 
// }
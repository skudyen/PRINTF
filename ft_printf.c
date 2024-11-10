/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuwaphr <nsuwaphr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:29:49 by nsuwaphr          #+#    #+#             */
/*   Updated: 2024/09/29 03:02:29 by nsuwaphr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_checkformat(va_list arg, const char alpha)
{
	int	len;

	len = 0;
	if (alpha == 'c')
		len += ft_print_c((char)va_arg(arg, int));
	else if (alpha == 's')
		len += ft_print_str(va_arg(arg, char *));
	else if (alpha == 'd' || alpha == 'i')
		len += ft_print_int(va_arg(arg, int));
	else if (alpha == 'u')
		len += ft_print_unsigned_int(va_arg(arg, unsigned int));
	else if (alpha == 'x')
		len += ft_print_hex(va_arg(arg, unsigned int));
	else if (alpha == 'X')
		len += ft_print_upperhex(va_arg(arg, unsigned int));
	else if (alpha == 'p')
		len += ft_print_ptr(va_arg(arg, void *));
	return (len);
}

int ft_printf(const char *str, ...)
{
	int cnt;
	va_list arg;

	va_start(arg, str);
	cnt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				cnt += write(1, "%", 1);
			else if (*str == 'c' || *str == 's' || *str == 'd' || *str == 'i'
				|| *str == 'u' ||*str == 'x' ||*str == 'X' ||*str == 'p')
				cnt += ft_checkformat(arg, *str);
			else
				break;
		}		
		else
			cnt += ft_print_c(*str);
		str++;
	}
	va_end(arg);
	return (cnt);
}

#include "ft_printf.h"
#include <stdio.h>

int main() {
    // Test case string NULL
    char *s = NULL;
    printf("ft_printf -> Buffer : %d\n", ft_printf("%s asdasdas", s));
    printf("printf -> Buffer : %d\n", printf("%s asdasdas", s));
    printf("-----------------------------------\n");

    // Test case character
    printf("ft_printf -> Buffer : %d\n", ft_printf("He%clo", 'l'));
    printf("printf -> Buffer : %d\n", printf("He%clo", 'l'));
    printf("-----------------------------------\n");

    // Test case string "Hello"
    printf("ft_printf -> Buffer : %d\n", ft_printf("%s", "Hello"));
    printf("printf -> Buffer : %d\n", printf("%s", "Hello"));
    printf("-----------------------------------\n");

    // Test case integer
    printf("ft_printf -> Buffer : %d\n", ft_printf("%d", 241124));
    printf("printf -> Buffer : %d\n", printf("%d", 241124));
    printf("-----------------------------------\n");

    // Test case unsigned integer
    printf("ft_printf -> Buffer : %d\n", ft_printf("%u", 2431124));
    printf("printf -> Buffer : %d\n", printf("%u", 2431124));
    printf("-----------------------------------\n");

    // Test case hex lower case
    printf("ft_printf -> Buffer : %d\n", ft_printf("%x", 255));
    printf("printf -> Buffer : %d\n", printf("%x", 255));
    printf("-----------------------------------\n");

    // Test case hex upper case
    printf("ft_printf -> Buffer : %d\n", ft_printf("%X", 255));
    printf("printf -> Buffer : %d\n", printf("%X", 255));
    printf("-----------------------------------\n");

    // Test case pointer
    int num = 42;
    void *ptr = &num;
    printf("ft_printf -> Buffer : %d\n", ft_printf("%p", ptr));
    printf("printf -> Buffer : %d\n", printf("%p", ptr));
    printf("-----------------------------------\n");

    // Test case NULL pointer
    void *null_ptr = NULL;
    printf("ft_printf -> Buffer : %d\n", ft_printf("%p", null_ptr));
    printf("printf -> Buffer : %d\n", printf("%p", null_ptr));
    printf("-----------------------------------\n");

    // Test case %%
    printf("ft_printf -> Buffer : %d\n", ft_printf("Percent sign: %%\n"));
    printf("printf -> Buffer : %d\n", printf("Percent sign: %%\n"));
    printf("-----------------------------------\n");

    return 0;
}


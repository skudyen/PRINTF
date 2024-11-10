/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuwaphr <nsuwaphr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:45:40 by nsuwaphr          #+#    #+#             */
/*   Updated: 2024/10/19 23:27:34 by nsuwaphr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int ft_print_c(char c);
int ft_print_str(char *str);
int ft_print_unsigned_int(unsigned int nb);
int ft_print_int(int nb);
int ft_print_hex(unsigned long nb);
int ft_print_upperhex(unsigned int nb);
int ft_print_ptr(void *ptr);

#endif

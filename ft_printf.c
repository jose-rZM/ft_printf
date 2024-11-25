/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:58:07 by jramire2          #+#    #+#             */
/*   Updated: 2024/11/25 21:58:09 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    handle_format(char format, va_list args)
{
    if (format == '%')
    {
        ft_putchar_fd('%', 1);
    }
    else if (format == 'c')
    {
        ft_putchar_fd(va_arg(args, int), 1);
    }
    else if (format == 's')
    {
        ft_putstr_fd(va_arg(args, char *), 1);
    }
    else if (format == 'p')
    {

    }
    else if (format == 'd')
    {
        ft_putnbr_fd(va_arg(args, int), 1);
    }
    else if (format == 'i')
    {
        ft_putnbr_fd(va_arg(args, int), 1);
    }
    else if (format == 'u')
    {

    }
    else if (format == 'x')
    {

    }
    else if (format == 'x')
    {

    }
    else if (format == 'X')
    {

    }
}

int ft_printf(char const *format, ...)
{
    size_t  i;
    va_list args;

    va_start(args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            ++i;
            handle_format(format[i], args);
        }
        else
        {
            ft_putchar_fd(format[i], 1); 
        }
        ++i;
    }
    va_end(args);
    return (0);
}
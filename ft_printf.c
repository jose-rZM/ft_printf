/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:45:53 by jramire2          #+#    #+#             */
/*   Updated: 2024/12/01 13:45:56 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned int n, char start)
{
	char	hex[9];
	char	*base;
	int		i;

	if (start == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	hex[8] = '\0';
	i = sizeof(hex) - 1;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	while (n != 0)
	{
		hex[i--] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(hex + i + 1, 1);
}

static int	print_address(void *ptr)
{
	char		buffer[2 + sizeof(uintptr_t) * 2 + 1];
	uintptr_t	value;
	const char	*hex;
	int			i;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	value = (uintptr_t)ptr;
	value = (uintptr_t)ptr;
	hex = "0123456789abcdef";
	i = sizeof(buffer) - 1;
	buffer[i--] = '\0';
	do
	{
		buffer[i--] = hex[value % 16];
		value /= 16;
	} 
    while (value > 0);
	buffer[i--] = 'x';
	buffer[i] = '0';
	write(1, &buffer[i], sizeof(buffer) - i - 1);
	return (sizeof(buffer) - i - 1);
}

static int	handle_format(char format, va_list args)
{
	if (format == '%')
		ft_putchar_fd('%', 1);
	else if (format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		print_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'x')
		return (print_hex(va_arg(args, int), 'x'));
	else if (format == 'X')
		return (print_hex(va_arg(args, int), 'X'));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	size_t	i;
	va_list	args;
	int		length;

	va_start(args, format);
	i = 0;
	length = 0;
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
			length++;
		}
		++i;
	}
	va_end(args);
	return (length);
}

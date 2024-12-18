/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:46:05 by jramire2          #+#    #+#             */
/*   Updated: 2024/12/01 13:46:08 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "format_numbers.h"

static int	print_address(void *ptr);
static int	handle_format(char format, va_list args);
int			ft_printf(char const *format, ...);

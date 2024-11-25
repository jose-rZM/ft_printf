/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:07:21 by jramire2          #+#    #+#             */
/*   Updated: 2024/11/25 22:07:22 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"


void    handle_format(char format, va_list args);
int ft_printf(char const *format, ...);

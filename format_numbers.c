/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:37 by jramire2          #+#    #+#             */
/*   Updated: 2024/12/04 13:51:39 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_numbers.h"

int putnbr_rec(unsigned int n)
{
    int ret1;
    int ret2;

    ret1 = 0;
    ret2 = 0;
	if (n < 10)
    {
        write(1, (int) n + '0', 1);
        return (1);
    }
    else
	{
		ret1 = putnbr_rec(n / 10);
		ret2 = putnbr_rec(n % 10);
        return (ret1 + ret2);
	}
}

int ft_putnbr(int n)
{
    if (n < 0)
    {
        write(1, '-', 1);
        return (1 + putnbr_rec(-n));
    }
    else
    {
        return (putnbr_rec(n));
    }
}
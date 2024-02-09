/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:02:15 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/09 20:40:32 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hcount(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	ft_put_hex(unsigned int n, const char format, int temp)
{
	if (n >= 16)
	{
		temp = ft_put_hex(n / 16, format, temp);
		if (temp < 0)
			return (-1);
		temp = ft_put_hex(n % 16, format, temp);
		if (temp < 0)
			return (-1);
	}
	else
	{
		if (n > 9)
		{
			if (format == 'x')
				if (ft_putchar(n - 10 + 'a') < 0)
					return (-1);
			if (format == 'X')
				if (ft_putchar(n - 10 + 'A') < 0)
					return (-1);
		}
		else
			return (ft_putchar(n + 48));
	}
	return (1);
}

int	ft_print_hex(unsigned int n, const char format)
{
	int	temp;

	temp = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	else
		if (ft_put_hex(n, format, temp) < 0)
			return (-1);
	return (ft_hcount(n));
}

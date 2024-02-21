/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:00:09 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/21 16:42:59 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long long a)
{
	int	len;

	len = 0;
	while (a != 0)
	{
		a /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hexx(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_hexx(n / 16);
		ft_put_hexx(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + 48);
	}
}

int	ft_pointer(unsigned long long n)
{
	int	len;
	int	temp;

	temp = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	if (n)
		temp = ft_putstr("0x");
	if (temp < 0)
		return (-1);
	else
		len += temp;
	if (n == 0)
	{
		if (ft_putchar('0') < 0)
			return (-1);
		len++;
	}
	else
		ft_put_hexx(n);
	return (hex_len(n) + len);
}

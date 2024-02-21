/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:20:26 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/09 19:00:42 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ucount(unsigned int i)
{
	int	ctr;

	ctr = 0;
	while (i)
	{
		i /= 10;
		ctr++;
	}
	return (ctr);
}

char	*ft_uitoa(unsigned int i)
{
	char	*s;
	int		len;

	len = ft_ucount(i);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	while (i)
	{
		s[--len] = i % 10 + 48;
		i /= 10;
	}
	return (s);
}

int	ft_putunsigned(unsigned int i)
{
	char	*s;
	int		len;

	if (!i)
	{
		return (ft_putchar('0'));
	}
	s = ft_uitoa(i);
	if (!s)
	{
		return (-1);
	}
	len = ft_putstr(s);
	if (len < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (len);
}

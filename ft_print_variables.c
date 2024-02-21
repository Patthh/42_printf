/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:14 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/09 20:41:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		if (ft_putchar(s[i]) < 0)
			return (-1);
		else
			i++;
	}
	return (i);
}

int	ft_putnbr(int i)
{
	char	*s;
	int		len;

	if (!i)
		return (ft_putchar('0'));
	s = ft_itoa(i);
	if (!s)
		return (-1);
	len = ft_putstr(s);
	if (len < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (len);
}

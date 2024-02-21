/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:16:31 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/21 16:39:52 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <inttypes.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_printf(const char *str, ...);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_pointer(unsigned long long ptr);
int		ft_putunsigned(unsigned int i);
int		ft_print_hex(unsigned int n, const char format);
int		ft_putnbr(int i);

char	*ft_uitoa(unsigned int i);
char	*ft_itoa(int n);

#endif

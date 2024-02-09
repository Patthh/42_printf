/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:16:31 by pracksaw          #+#    #+#             */
/*   Updated: 2024/02/09 20:25:59 by pracksaw         ###   ########.fr       */
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

// main
size_t	ft_printf(const char *str, ...);

// print
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_ptr(unsigned long long ptr);
int		ft_putunsigned(unsigned int i);
int		ft_print_hex(unsigned int n, const char format);
int		ft_putnbr(int i);

// convert
char	*ft_uitoa(unsigned int i);
char	*ft_itoa(int n);

#endif

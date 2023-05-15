/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:08:23 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/13 01:08:36 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_print(char c, va_list args);
void	ft_putchar(va_list args);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void	ft_puthex(int n, int caps);
void	ft_print_adress_hex(char *p);

#endif

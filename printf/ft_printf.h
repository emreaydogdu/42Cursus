/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:08:23 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/21 11:42:17 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	char	c;
	int		len;
	int		hash;
	int		plus;
	int		space;
}	t_print;

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_count_digits(int n);
int	ft_putnbr(int n, t_print *p);
int	ft_putnbr_b(int n, t_print *p);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, int caps, t_print *p);
int	ft_puthexp(unsigned long n);
int	ft_puthexph(unsigned long n);
//int	ft_formats(va_list args, const char c, t_print *p);
int	ft_printf(const char *str, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:08:23 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/22 23:04:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_print
{
	char	c;
	int		len;
	int		hash;
	int		plus;
	int		space;
	char	pad;
	int		minus;
	int	width;
	int		dot;
	int		precision;
}	t_print;

int	ft_putchar(char c, t_print *p);
int	ft_putstr(char *s, t_print *p);

int	ft_count_digits(long n, t_print *p);
int	ft_putnbr_b(int n, t_print *p);
int	ft_putnbr(int n, t_print *p);
int	ft_putunbr(unsigned int n, t_print *p);
int	ft_putunbr_b(unsigned int n, t_print *p);

int	ft_puthex(unsigned int n, int caps, t_print *p);
int	ft_puthex_h(unsigned int n, int caps, t_print *p);
int	ft_putptr(unsigned long n, t_print *p);
int	ft_putptr_h(unsigned long n);
int	ft_putptr_c(unsigned long n);

//int	ft_formats(va_list args, const char c, t_print *p);
int	ft_strlen(const char *s);
int	ft_printf(const char *str, ...);

int		ft_print_width(int n, t_print *p);
void	ft_check_b1(char **format, t_print *p);
void	ft_check_b2(char **format, t_print *p);
int		ft_pplus(t_print *p);
int		ft_pspace(t_print *p);

#endif

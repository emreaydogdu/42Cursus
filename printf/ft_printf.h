/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 15:04:35 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_print
{
	int	spec;
	int	width;
	int	minus;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
	int	size;
}		t_print;

int		ft_printf(const char *format, ...);
void	ft_putarg(char type, va_list args, t_print *p);

int		ft_putchar(char c);
int		ft_putchar_f(char c, t_print p);
int		ft_puts(const char *str);
int		ft_putstr_f(const char *str, t_print p);
int		ft_putnumbr_f(int n, t_print p);
int		ft_putunumbr_f(unsigned int n, t_print p);
int		ft_puthex_f(unsigned int n, int is_upper, t_print p);
int		ft_putptr_f(unsigned long int n, t_print p);

char	*ft_itoa_h(long nb);
char	*ft_utoa_h(unsigned int nb);
char	*ft_xtoa_h(unsigned long int nb, int is_upper);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);
int		ft_putwidth(int width, int size, int zero);
void	ft_reset(t_print *p);
void	ft_minus(t_print *p);
void	ft_width_num(char c, t_print *p);
void	ft_width(va_list args, t_print *p);
int		ft_precision(const char *str, int pos, va_list args, t_print *p);
size_t	ft_strlen(const char *str);
void	*ft_callocc(size_t count, size_t size);
int		ft_isdigit(int c);

#endif

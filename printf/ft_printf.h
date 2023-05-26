/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:25:09 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 18:40:04 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# if defined (__linux__)
#  define PTRNULL "(nil)"
# elif defined (__APPLE__)
#  define PTRNULL "0x0"
# endif

/* ---------- FLAGS --------------------- */
typedef struct s_flags
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
}		t_flags;

t_flags	ft_reset_flags(t_flags flags);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
int		ft_putarg(char type, va_list args, t_flags flags);

/* ---------- PRINT SPECIFIERS ---------- */
// c
int		ft_putchar_f(char c, t_flags flags);
int		ft_putchar(char c);
// s
int		ft_putstr_f(const char *str, t_flags flags);
int		ft_print_s(const char *str);
int		ft_print_s_pre(const char *str, int precision);
int		ft_print_sign_pre(int n, t_flags *flags);
// i, d
int		ft_putnumbr_f(int n, t_flags flags);
int		ft_putnumbr(char *nbstr, int n, t_flags flags);
int		ft_print_i(char *nbstr, int n, t_flags flags);
// u
int		ft_putunumbr_f(unsigned int n, t_flags flags);
int		ft_print_u(char *nbstr, t_flags flags);
int		ft_putunumbr(char *nbstr, t_flags flags);
// x, X
int		ft_puthex_f(unsigned int n, int is_upper, t_flags flags);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_puthex(char *nbstr, int n, int is_upper, t_flags flags);
// p
int		ft_putptr_f(unsigned long int n, t_flags flags);
int		ft_putptr(unsigned long int n);
void	ft_print_adr(unsigned long int n);

/* ---------- HELPER FUNCTIONS ---------- */
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long int nb, int is_upper);
int		ft_unint_len(unsigned int n);
int		ft_hex_len(unsigned int n);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

/* ---------- FLAG FUNCTIONS ------------ */
int		ft_putwidth(int total_width, int size, int zero);

#endif

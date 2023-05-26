/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:04:06 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

void	ft_reset(t_flags *p);
void	ft_minus(t_flags *p);
void	ft_width_num(char c, t_flags *p);
void	ft_width(va_list args, t_flags *p);
int		ft_precision(const char *str, int pos, va_list args, t_flags *flags);

/* ---------- LIBFT -------------------- */
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int	ft_isdigit(int c);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
void	ft_putarg(char type, va_list args, t_flags *flags);

// c
int		ft_putchar(char c);
int		ft_putchar_f(char c, t_flags flags);
// s
int		ft_print_s(const char *str);
int		ft_putstr_f(const char *str, t_flags flags);
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
char	*ft_itoa_h(long nb);
char	*ft_utoa_h(unsigned int nb);
char	*ft_xtoa_h(unsigned long int nb, int is_upper);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

/* ---------- FLAG FUNCTIONS ------------ */
int		ft_putwidth(int total_width, int size, int zero);

#endif

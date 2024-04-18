/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:14 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:34:04 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_formatted(char *format, va_list arg, int fd)
{
	if (*format && *(format + 1))
	{
		if (*(format + 1) == 'c')
			return (ft_check_print_c(format, arg, fd));
		if (*(format + 1) == 's')
			return (ft_check_print_s(format, arg, fd));
		if (*(format + 1) == 'd' || *(format + 1) == 'i')
			return (ft_check_print_d_i(format, arg, fd));
		if (*(format + 1) == 'u')
			return (ft_check_print_u(format, arg, fd));
		if (*(format + 1) == 'x')
			return (ft_check_print_x(format, arg, fd));
		if (*(format + 1) == 'X')
			return (ft_check_print_u_x(format, arg, fd));
		if (*(format + 1) == 'p')
			return (ft_check_print_p(format, arg, fd));
		if (ft_check_print_perc(format, fd))
			return (1);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			arglist;
	int				ret;
	int				len;

	len = 0;
	va_start(arglist, format);
	while (*format)
	{
		while (*format != '%' && *(format))
		{
			write(1, format++, 1);
			len++;
		}
		if (*format)
		{
			ret = ft_print_formatted((char *)format, arglist, 1);
			if (ret == -1)
				return (-1);
			len += ret;
			format += 2;
		}
	}
	va_end(arglist);
	return (len);
}

/* void	ft_check_equality(int b, int c)
{
	if (b == c)
		printf("\nCorretto il return\n\tmio = %d\tsuo = %d\n\n", b, c);
	else
		printf("\nErrato il return\n\tmio = %d\tsuo = %d\n\n", b, c);
}
int main() {
	int a = 0;
	int b = ft_printf("Hello, %s!", "world");
	int c = printf("Hello, %s!", "world");
	ft_check_equality(b, c);
	// ft_printf("char %c", '0');
	// ft_printf("char %c\n", '0'); 
	// b = ft_printf("The ans%%wer is %d", -1);
	// c = printf("The ans%%wer is %d", -1);
	// ft_check_equality(b, c); 
	// b = ft_printf("MIO hexa min = %x\thexa upper = %X\n", LONG_MIN, -11);
	// c = printf("SUO hexa min = %x\thexa upper = %X\n",LONG_MIN, -11);
	// ft_check_equality(b, c);
	b = ft_printf("mio pointer = %p\t%p", LONG_MIN, LONG_MAX);
	c = printf("suo pointer = %p\t%p", LONG_MIN, LONG_MAX);
	ft_check_equality(b, c); 
	return 0;
}  */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:30:06 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:33:17 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
/******************************************************************************/
/*                     Functions from <libc.h>                                */
/******************************************************************************/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/******************************************************************************/
/*                     Functions from <string.h>                              */
/******************************************************************************/
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
/******************************************************************************/
/*                     Functions from <stdlib.h>                              */
/******************************************************************************/
int				ft_atoi(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
/******************************************************************************/
/*                     Non-standard functions                                 */
/******************************************************************************/
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
/******************************************************************************/
/*                     Linked list functions                                  */
/******************************************************************************/
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
/******************************************************************************/
/*                     		Printf functions                                  */
/******************************************************************************/
int				ft_puthexa_l_fd(unsigned int nb, int fd);
int				ft_puthexa_u_fd(unsigned int nb, int fd);
int				ft_putunbr_fd(unsigned int n, int fd);
int				ft_putptr_fd(unsigned long int nb, int fd);
int				ft_printf(const char *format, ...);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_print_formatted(char *format, va_list arg, int fd);
int				ft_check_print_c(char *format, va_list arg, int fd);
int				ft_check_print_s(char *format, va_list arg, int fd);
int				ft_check_print_d_i(char *format, va_list arg, int fd);
int				ft_check_print_perc(char *format, int fd);
int				ft_check_print_u(char *format, va_list arg, int fd);
int				ft_check_print_x(char *format, va_list arg, int fd);
int				ft_check_print_u_x(char *format, va_list arg, int fd);
int				ft_check_print_p(char *format, va_list arg, int fd);
int				ft_numlen(int num);
/******************************************************************************/
/*                     		Math functions                                    */
/******************************************************************************/
float			ft_strtof(const char *str);
double			abs_double(double n);
#endif

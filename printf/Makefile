.PHONY: all bonus clean fclean re

NAME = libftprintf.a
SRC = ft_printf.c ft_putc.c ft_puts.c ft_putx.c ft_putn.c ft_putp.c ft_putu.c ft_libft ft_conversions.c ft_conversions_h.c ft_itoa.c ft_utoa.c ft_xtoa.c
OBJS = ${B_SRCS:.c=.o}
AR = ar
ARFLAGS = rc
RM = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: all

clean:
	rm -f ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

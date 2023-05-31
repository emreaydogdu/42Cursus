.PHONY: all bonus clean fclean re

NAME = libftprintf.a
SRC = ft_printf.c ft_putc.c ft_puts.c ft_putx.c ft_putn.c ft_putp.c ft_putu.c ft_libft.c ft_conversions.c ft_conversions_h.c ft_itoa.c ft_utoa.c ft_xtoa.c
OBJS = ${SRC:.c=.o}
AR = ar
ARFLAGS = rc
RM = rm
CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: all

clean:
	$(RM) -f ${OBJS}

fclean: clean
	$(RM) -f $(NAME)

re: fclean all


SRCS = ft_printf.c ft_puts.c
B_SRCS = ft_printf.c ft_puts.c
OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}
NAME  = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

#bonus: ${NAME} ${B_OBJS}
#	ar rc ${NAME} ${B_OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

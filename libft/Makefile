SRCS = $(wildcard ft_*.c)
B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}
NAME  = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${NAME} ${B_OBJS}
	ar rc ${NAME} ${B_OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

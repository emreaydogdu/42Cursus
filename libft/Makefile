SRCS = $(wildcard ft_*.c)
B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}
LIB  = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${LIB}

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

${LIB} : ${OBJS}
	ar rc ${LIB} ${OBJS}

bonus: ${LIB} ${B_OBJS}
	ar rc ${LIB} ${B_OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${LIB}

re: fclean all

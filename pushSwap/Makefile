.PHONY: all bonus clean fclean re

NAME = push_swap
SRC = push_swap.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_sort.c ft_stack.c ft_place.c ft_libft.c
OBJS = ${SRC:.c=.o}
RM = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o push_swap

bonus: all

clean:
	rm -f ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

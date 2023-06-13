.PHONY: all bonus clean fclean re

NAME = push_swap
SRC = push_swap.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_sort.c ft_stack.c ft_place.c ft_libft.c ft_operation.c
SRC_B = checker.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_stack.c ft_libft.c
OBJS = ${SRC:.c=.o}
RM = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) lib/libft.a  -o push_swap

bonus: all
	$(CC) $(CFLAGS) $(SRC_B) lib/libft.a  -o checker

clean:
	rm -f ${OBJS}

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

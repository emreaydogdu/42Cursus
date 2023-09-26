.PHONY: all bonus clean fclean re libft

NAME = push_swap
SRC = push_swap.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_sort.c ft_stack.c ft_place.c ft_libft.c ft_operation.c
SRC_B = checker.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_stack.c ft_libft.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	@echo "Make PUSHSWAP"
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o push_swap

bonus: all
	@$(CC) $(CFLAGS) $(SRC_B) $(LIBFT) -o checker

clean:
	@echo "Clean .o files"
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@echo "Clean everything"
	@make fclean -C libft
	@rm -f $(NAME) checker

re: fclean all

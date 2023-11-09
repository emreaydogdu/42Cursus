.PHONY: all bonus clean fclean re libft

NAME = push_swap
SRC = push_swap.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_sort.c ft_stack.c ft_place.c ft_libft.c ft_operation.c
SRC_B = checker.c ft_error.c ft_find.c ft_lst.c ft_p.c ft_r.c ft_rr.c ft_s.c ft_stack.c ft_libft.c
OBJ = push_swap.o ft_error.o ft_find.o ft_lst.o ft_p.o ft_r.o ft_rr.o ft_s.o ft_sort.o ft_stack.o ft_place.o ft_libft.o ft_operation.o
OBJ_B = checker.o ft_error.o ft_find.o ft_lst.o ft_p.o ft_r.o ft_rr.o ft_s.o ft_stack.o ft_libft.o
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

all: $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@echo "Make PUSHSWAP"
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o push_swap

bonus: $(LIBFT) $(OBJ_B)
	@$(CC) $(CFLAGS) $(SRC_B) $(LIBFT) -o checker

clean:
	@echo "Clean .o files"
	@make clean -C libft
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@echo "Clean everything"
	@make fclean -C libft
	@rm -f $(NAME) checker

re: fclean all

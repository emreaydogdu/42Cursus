NAME = so_long
SRC = ft_so_long.c ft_parse_map.c ft_draw_map.c ft_hook.c ft_error.c getNextLine/get_next_line.c getNextLine/get_next_line_utils.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
LIBFT = ./libft/libft.a
MLX = ./MLX42/build/libmlx42.a

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C ./libft

$(MLX):
	@echo "Make MLX Library"
	@cd MLX42 && cmake -B build && make -s -C build

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "Make so_long"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	@echo "Clear"
	@make -s clean -C ./libft
	@$(RM) -rf ${OBJS}

fclean: clean
	@make -s clean -C ./MLX42/build
	@make -s fclean -C ./libft
	@$(RM) -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re
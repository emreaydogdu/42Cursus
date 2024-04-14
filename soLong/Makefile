.PHONY: all bonus clean fclean re

NAME = solong
SRC = ft_solong.c ft_parse_map.c ft_draw_map.c ft_draw.c ft_hook.c ft_hook_h1.c ft_hook_h2.c ft_error.c getNextLine/get_next_line.c getNextLine/get_next_line_utils.c
OBJS = ${SRC:.c=.o}
RM = rm
CC = cc
LIBFT = libft/libft.a
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	@echo "Make so_long"
	$(CC) $(OBJS) $(LIBFT) MLX/libmlx42.a -Iinclude -lglfw -o $(NAME)
	@#$(CC) $(OBJS) MLX/libmlx42.a libft/libft.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -o $(NAME)

bonus: all

clean:
	@echo "Clean .o"
	@make clean -C libft
	@$(RM) -f ${OBJS}

fclean: clean
	@echo "Clean everything"
	@make fclean -C libft
	@$(RM) -f $(NAME)

re: fclean all


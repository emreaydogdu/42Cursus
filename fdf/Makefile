.PHONY: all bonus clean fclean re

NAME = fdf
SRC = ft_fdf.c ft_map.c ft_draw.c ft_menu.c ft_atoi_base.c ft_hooks.c ft_color.c getNextLine/get_next_line.c getNextLine/get_next_line_utils.c
OBJS = ${SRC:.c=.o}
RM = rm
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(NAME)

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	@echo "Make FDF"
	@$(CC) $(OBJS) MLX/libmlx42.a $(LIBFT) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@#$(CC) $(OBJS) MLX/libmlx42.a $(LIBFT) -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -o $(NAME)
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


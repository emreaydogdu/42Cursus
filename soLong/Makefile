.PHONY: all bonus clean fclean re

NAME = solong
SRC = ft_solong.c ft_parse_map.c  ft_draw_map.c ft_draw.c ft_hook.c ft_atoi_base.c getNextLine/get_next_line.c getNextLine/get_next_line_utils.c
OBJS = ${SRC:.c=.o}
RM = rm
CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	##$(CC) $(OBJS) MLX/libmlx42.a libft/libft.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -o $(NAME)
	$(CC) $(OBJS) libft/libft.a MLX/libmlx42.a -Iinclude -lglfw -o $(NAME)

bonus: all

clean:
	$(RM) -f ${OBJS}

fclean: clean
	$(RM) -f $(NAME)

re: fclean all


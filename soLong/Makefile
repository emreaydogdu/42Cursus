NAME = solong
SRC = so_long.c ft_parse_map.c ft_draw_map.c ft_draw.c ft_hook.c ft_hook_h1.c ft_hook_h2.c ft_error.c getNextLine/get_next_line.c getNextLine/get_next_line_utils.c
NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

MLXFLAGS=	./MLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

LIBS	=	 ./libft/libft.a

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C  ./MLX42
			make -C  ./libft
			$(CC)  $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
			make clean -C  ./MLX42
			make clean -C  ./libft
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: clean fclean re
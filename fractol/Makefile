NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
PFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
#CFLAGS = -Wall -Wextra -Werror
#PFLAGS = -lXext -lX11 -o
RM = rm -f -r
DIR_OBJ = obj
DIR_SRC = src
SOURCES = main.c draw.c julia.c mandelbrot.c hooks.c utils.c error.c
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
LIBFT = libft
MINLIBX = minilibx-linux
HEADER = inc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating libft.a"
	@make -s -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@echo "Creating libmlx_Linux.a"
	@make -s -C $(MINLIBX)
	@cp $(MINLIBX)/libmlx_Linux.a .
	@echo "Creating $(NAME)."
	@$(CC) $(CFLAGS) $(OBJS) libft.a libmlx_Linux.a $(PFLAGS) $(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@echo "Clear Objects"
	@$(RM) $(DIR_OBJ)
	@make -s -C $(LIBFT) fclean

fclean: clean
	@echo "Clear fractol"
	@$(RM) $(NAME) libft.a libmlx_Linux.a
	@make -s -C $(LIBFT) fclean
	@make -s -C $(MINLIBX) clean

re: fclean all

.PHONY: all clean fclean re
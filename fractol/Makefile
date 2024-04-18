NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
PFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
RM = rm -f
AR = ar rcs
DIR_OBJ = obj
DIR_SRC = src
SOURCES = burningship.c \
          draw.c \
          julia.c \
          key_hooks.c \
		  main.c \
		  mandelbrot.c \
		  mouse_hooks.c \
		  utils.c \
		  tricorn.c
LIBFT = libft
MINLIBX = minilibx-linux
HEADER = inc
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
NORM = norminette ./$(DIR_SRC) ./$(LIBFT) ./$(HEADER)
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
BOLD = $(shell tput bold)

title: all

all: $(NAME)
$(NAME): $(OBJS)
	@echo "$(COLOR_BLUE)Creating libft.a and copying it to root directory.$(COLOR_END)"
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo "$(COLOR_BLUE)Creating libmlx_Linux.a and copying it to root directory.$(COLOR_END)"
	make -C $(MINLIBX)
	cp $(MINLIBX)/libmlx_Linux.a .
	@echo "$(COLOR_BLUE)Creating $(NAME).$(COLOR_END)"
	$(CC) $(OBJS) libft.a libmlx_Linux.a $(PFLAGS) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	# @echo "Compiling $< into $@.\n"
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	# @echo "$(COLOR_GREEN)Compiled.✅$(COLOR_END)"

clean:
	clear
	@echo "$(COLOR_BLUE)Cleaning object files.$(COLOR_END)"
	$(RM) -r $(DIR_OBJ)/*.o
	@echo "$(COLOR_GREEN)$(NAME) object files cleaned.✅$(COLOR_END)"

fclean: clean
	@echo "$(COLOR_BLUE)Cleaning $(NAME) and libft.$(COLOR_END)"
	$(RM) $(NAME) libft.a libmlx_Linux.a
	make -C $(LIBFT) fclean
	make -C $(MINLIBX) clean
	clear
	@echo "$(COLOR_GREEN)Project $(NAME) cleaned.✅$(COLOR_END)"

re: fclean all title

readme:
	clear
	cat README.c

.PHONY: all clean fclean re
.SILENT: clean fclean re $(NAME) $(OBJS) $(DIR_OBJ)/%.o $(DIR_SRC)/%.c readme

title:
	@clear
	@echo "$(COLOR_RED)$(BOLD)8 8888888888   8 888888888o.            .8.           ,o888888o."
	@echo "8 8888         8 8888    '88.          .888.         8888     '88."
	@echo "8 8888         8 8888     '88         :88888.     ,8 8888       '8."
	@echo "8 8888         8 8888     ,88        . '88888.    88 8888"
	@echo "8 888888888888 8 8888.   ,88'       .8. '88888.   88 8888"
	@echo "8 8888         8 888888888P'       .8'8. '88888.  88 8888"
	@echo "8 8888         8 8888'8b          .8' '8. '88888. 88 8888"
	@echo "8 8888         8 8888 '8b.       .8'   '8. '88888.'8 8888       .8'"
	@echo "8 8888         8 8888   '8b.    .888888888. '88888.  8888     ,88'"
	@echo "8 8888         8 8888     '88. .8'       '8. '88888.  '8888888P'"
	@echo " "
	@echo "8888888 8888888888 ,o888888o.     8 8888"
	@echo "      8 8888    . 8888     '88.   8 8888"
	@echo "      8 8888   ,8 8888       '8b  8 8888"
	@echo "      8 8888   88 8888        '8b 8 8888"
	@echo "      8 8888   88 8888         88 8 8888"
	@echo "      8 8888   88 8888         88 8 8888"
	@echo "      8 8888   88 8888        ,8P 8 8888"
	@echo "      8 8888   '8 8888       ,8P  8 8888"
	@echo "      8 8888    ' 8888     ,88'   8 8888"
	@echo "      8 8888       '8888888P'     8 888888888888$(COLOR_END)"
	@echo " "
	@echo "$(COLOR_GREEN)                                     ,_"
	@echo "                                   iW@@Wi\ "
	@echo "                                  !@@@@f\ "
	@echo "                          __ ,gsmWmmWWmmmmsz\ "
	@echo "                          M@W@@@@@@@@@@@@@@@@bd@P\ "
	@echo "                       ,sm@@@@@@@@@@@@@@@@@@@@@W_\ "
	@echo "                      ,m@@@@@@@@@@@@@@@@@@@@@@@@@s.\ "
	@echo "          s.,_s..    ,W@@@@@@@@@@@@@@@@@@@@@@@@@@W\ "
	@echo "        ,_@@@@@@@Ws. d@@@@@@@@@@@@@@@@@@@@@@@@@@@@\' "
	@echo "        W@@@@@@@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@A\ "
	@echo "    i@@W@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@P\' "
	@echo "     ~~\'@@@@@@@@@@@@!@@@@@@@@@@@@@@@@@@@@@@@@@@@Ws\ "
	@echo "        !*@@@@@@@@Af M@@@@@@@@@@@@@@@@@@@@@@@@@@@@\ "
	@echo "          AfV*Aff\'   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@\' "
	@echo "                      !@@@@@@@@@@@@@@@@@@@@@@@@@@D-\ "
	@echo "                       -A@@@@@@@@@@@@@@@@@@@@@@@*\ "
	@echo "                          8@@@@@@@@@@@@@@@@@@AMWi\ "
	@echo "                          **'VMA@@@@@@@@@@AK~\''~~\ "
	@echo "                                 \',mWWm.\ "
	@echo "                                   @@@@P\ "
	@echo "                                    'V*\' $(COLOR_END)"
	@echo " "
	@echo "$(COLOR_BLUE)$(BOLD)Fractol is a project that consists in creating a small fractal exploration program.$(COLOR_END)"
	@echo "$(COLOR_BLUE)$(BOLD)This program is able to display four different fractals: Mandelbrot, Julia, Burning Ships and Tricorn.$(COLOR_END)"
	@echo "$(COLOR_BLUE)$(BOLD)The program is able to zoom in and out, change the color palette, change the iterations and move the fractal.$(COLOR_END)"
	@echo "$(COLOR_BLUE)$(BOLD)Type ./fractol to show available flags. For more informations: make readme$(COLOR_END)"

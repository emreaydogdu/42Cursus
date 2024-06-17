# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 16:37:51 by hhagiwar          #+#    #+#              #
#    Updated: 2023/09/22 22:49:58 by hhagiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
SRC = src/main.c \
		src/error.c \
		src/ft_atoi.c \
		src/set.c \
		src/philosophers.c \
		src/util.c \
		src/action.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
# notdir 関数は、パスからディレクトリ部分を削除してファイル名だけを取得する関数
# addprefix 関数は、第一引数に指定した文字列を、第二引数に指定した文字列の前に付ける関数

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@printf "\e[38;5;82msuccessfully built🚀\e[0m\n"

# -fsanitize=thread
# $(CC) $(PRINT) $(GNL) $(OBJ) -o $(NAME)
clean: 
	$(RM) $(RMFLAGS) $(OBJ_DIR)/*.o
    
fclean: clean 
	$(RM) $(RMFLAGS) $(NAME)
	@printf "\e[38;5;208msuccessfully deleted🗑\e[0m\n"

push: 
	git add .
	git commit -m "auto commit"
	git push

re: fclean all 

.PHONY: all clean fclean re help


LIBFT_PATH		= $(PARENT_DIR)

UTILS			= $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
PARENT_DIR		= $(shell dirname $(shell pwd))

TESTS_PATH		= tests/
SRCS	= memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd striteri
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
OBJS = ${SRCS:.c=.o}
RUN = run
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all:
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -c main.c
	@$(CC) $(CFLAGS) main.c -L$(LIBFT_PATH) -lft && $(VALGRIND) ./a.out && rm -f a.out main.o

clean:
	make clean -C $(LIBFT_PATH) && rm -rf a.out*

fclean:
	make fclean -C $(LIBFT_PATH) && rm -rf a.out*


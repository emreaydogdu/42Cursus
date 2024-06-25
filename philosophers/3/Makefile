NAME	=	philo
CC		=	cc
CFLAGS	=	#-Wall -Wextra -Werror
RM		=	rm -f -r

SRCC	=	philosophers.c utils.c atoitoa.c init.c philo_functions.c threads.c
OBJD	=	obj
SRCD	=	src
SRCS	=	$(addprefix $(SRCD)/,$(SRCC))
OBJS	=	$(addprefix $(OBJD)/,$(SRCC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "Compile program"

$(OBJD)/%.o: $(SRCD)/%.c
			@mkdir -p $(OBJD)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJD)
			@echo "Remove object files"
			
fclean:		clean
			@$(RM) $(NAME)
			@echo "Remove program"

re:			fclean all

.PHONY:		all clean fclean re

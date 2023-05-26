NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf ft_putc ft_puts ft_putx ft_putn ft_putp ft_putu ft_libft ft_conversions ft_conversions_h ft_itoa ft_utoa ft_xtoa
SRCS 			=	$(addsuffix .c, $(SRC))

OBJS			=	$(SRCS:%.c=%.o)

%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
					rm -f ${OBJS}

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re
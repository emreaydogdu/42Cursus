NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf ft_putc ft_puts ft_putx ft_putn ft_putp ft_putu ft_libft ft_conversions ft_conversions_h ft_itoa ft_utoa ft_xtoa
SRCS 			=	$(addsuffix .c, $(SRC))

OBJS			=	$(SRCS:%.c=%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					rm -f ${OBJS}
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft
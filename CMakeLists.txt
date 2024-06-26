cmake_minimum_required(VERSION 3.25)
project(42Cursus C)

set(CMAKE_C_STANDARD 11)

add_executable(42Cursus test/main.c libft/libft.h libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_substr.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c fdf/ft_map.c)
add_executable(printff printf/ft_printf.h printf/ft_printf.h printf/ft_conversions.c printf/ft_conversions_h.c printf/ft_putc.c printf/ft_putx.c printf/ft_putn.c printf/ft_putp.c printf/ft_puts.c printf/ft_putu.c printf/ft_printf.c printf/ft_itoa.c printf/ft_utoa.c printf/ft_xtoa.c printf/ft_libft.c)
add_executable(getNextLine getNextLine/get_next_line.h getNextLine/get_next_line.c getNextLine/file getNextLine/get_next_line_utils.c)
add_executable(getNextLine_bonus getNextLine/file getNextLine/file_bonus getNextLine/get_next_line_bonus.c getNextLine/get_next_line_utils_bonus.c getNextLine/get_next_line_bonus.h)
add_executable(server minitalk/server.c)
add_executable(client minitalk/client.c)
add_executable(fractol fractol/src/draw.c fractol/src/error.c fractol/src/julia.c fractol/src/hooks.c fractol/src/main.c fractol/src/mandelbrot.c fractol/src/utils.c)
add_executable(soLong soLong/ft_so_long.c soLong/ft_parse_map.c soLong/ft_error.c)
add_executable(fdf fdf/ft_fdf.c fdf/MLX/MLX42.h fdf/MLX/libmlx42.a fdf/getNextLine/get_next_line_utils.c fdf/getNextLine/get_next_line.c fdf/ft_draw.c fdf/ft_menu.c fdf/ft_atoi_base.c fdf/ft_hooks.c fdf/ft_color.c)
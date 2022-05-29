NAME = so_long
CFLAGS = -Wall -Werror -Wextra
FLAGS = -crs
mlx = ./mlx/libmlx.a
FILES = so_long.c init_map.c check_format.c check_map.c utils.c
OBJECTS = $(FILES:.c=.o)
LIBFT = cd libft && make
LIB = libft/libft.a
$(NAME)	:
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit
all : $(NAME)
clean :
		rm -f $(OBJS)
		make clean -C mlx
	
fclean : clean
		rm -f $(NAME)
		make clean -C mlx
re : fclean all
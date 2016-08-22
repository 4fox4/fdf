SRC =	fdf.c hook.c parser.c draw.c iso_converter.c ft_init.c error.c \
		ft_color.c

OBJ =	fdf.o hook.o parser.o draw.o iso_converter.o ft_init.o error.o \
		ft_color.o

LIB = libft/libft.a

INC = libft/

NAME = fdf

FLAGS = -Wall -Wextra -Werror

XFLAG = -framework OpenGL -framework AppKit

all: libft.a mlx $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -c $(SRC) -I $(INC)
	gcc -o $(NAME) $(OBJ) $(XFLAG) $(LIB) minilibx_macos/libmlx.a

mlx:
	make -C minilibx_macos/

libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean

re: fclean all

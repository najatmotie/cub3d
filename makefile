NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRC = main.c ray_casting/utils.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) cub3d.h
	cc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all fclean
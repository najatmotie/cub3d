NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

DEPENDECES = -framework Cocoa -framework OpenGL -framework IOKit

GLFW = /goinfre/nmotie-/homebrew/opt/glfw/lib

SRC = main.c globals.c events.c libft_utils.c drawing.c raycasting.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) cub3d.h
	cc $(OBJ) MLX42/build/libmlx42.a $(DEPENDECES) -Iinclude -lglfw  -fsanitize=address -g -L$(GLFW) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

DEPENDECES = -framework Cocoa -framework OpenGL -framework IOKit

GLFW = /goinfre/nmotie-/homebrew/opt/glfw/lib

MLXLIB = MLX42/build/libmlx42.a

SRC = main.c parsing_map/checks.c parsing_map/file_extension.c parsing_map/fill_map.c \
	raycasting/moves.c raycasting/utils.c raycasting/drawing.c raycasting/raycasting.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) cub3d.h
	cc $(OBJ) $(DEPENDECES) -Iinclude -lglfw  -L$(GLFW) $(MLXLIB) -fsanitize=address -g -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
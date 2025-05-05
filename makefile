NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

DEPENDECES = -framework Cocoa -framework OpenGL -framework IOKit

GLFW = /goinfre/nmotie-/homebrew/opt/glfw/lib

MLXLIB = MLX42/build/libmlx42.a

SRC = main.c gnl/get_next_line.c libft/ft_atoi.c libft/ft_split.c libft/ft_strchr.c \
	libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strrchr.c \
	parsing/file_extension.c parsing/parsing_file.c \
	parsing/map/parse_map.c parsing/map/map_utils.c parsing/map/player_data.c parsing/map/check_errors.c \
	parsing/texture/get_images.c parsing/texture/get_colors.c parsing/texture/parse_textures.c parsing/texture/texture_utils.c \
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
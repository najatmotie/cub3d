NAME = cub3D

NAMEB = cub3D_bonus

CFLAGS = -Wall -Wextra -Werror

DEPENDECES = -framework Cocoa -framework OpenGL -framework IOKit

GLFW = /goinfre/nmotie-/homebrew/opt/glfw/lib

MLXLIB = MLX42/build/libmlx42.a

SRC = mandatory/gnl/get_next_line.c mandatory/libft/ft_atoi.c mandatory/libft/ft_split.c mandatory/libft/ft_strchr.c \
	mandatory/libft/ft_strcmp.c mandatory/libft/ft_strdup.c mandatory/libft/ft_strjoin.c mandatory/libft/ft_strlen.c mandatory/libft/ft_strrchr.c \
	mandatory/main.c mandatory/moves.c mandatory/game.c mandatory/utils.c mandatory/parsing/file_extension.c mandatory/parsing/parsing_file.c \
	mandatory/parsing/map/parse_map.c mandatory/parsing/map/map_utils.c mandatory/parsing/map/player_data.c mandatory/parsing/map/check_errors.c \
	mandatory/parsing/texture/get_images.c mandatory/parsing/texture/get_colors.c mandatory/parsing/texture/parse_textures.c mandatory/parsing/texture/texture_utils.c \
	mandatory/raycasting/ray_casting.c mandatory/raycasting/helper_funcs.c mandatory/raycasting/vertical.c mandatory/raycasting/horisontal.c \
	mandatory/rendering/3d.c

SRCB = bonus/gnl/get_next_line_bonus.c bonus/libft/ft_atoi_bonus.c bonus/libft/ft_split_bonus.c bonus/libft/ft_strchr_bonus.c \
	bonus/libft/ft_strcmp_bonus.c bonus/libft/ft_strdup_bonus.c bonus/libft/ft_strjoin_bonus.c bonus/libft/ft_strlen_bonus.c bonus/libft/ft_strrchr_bonus.c \
	bonus/main_bonus.c bonus/moves_bonus.c bonus/game_bonus.c bonus/utils_bonus.c bonus/parsing/file_extension_bonus.c bonus/parsing/parsing_file_bonus.c \
	bonus/parsing/map/parse_map_bonus.c bonus/parsing/map/map_utils_bonus.c bonus/parsing/map/player_data_bonus.c bonus/parsing/map/check_errors_bonus.c \
	bonus/parsing/texture/get_images_bonus.c bonus/parsing/texture/get_colors_bonus.c bonus/parsing/texture/parse_textures_bonus.c bonus/parsing/texture/texture_utils_bonus.c \
	bonus/raycasting/ray_casting_bonus.c bonus/raycasting/helper_funcs_bonus.c bonus/raycasting/vertical_bonus.c bonus/raycasting/horisontal_bonus.c \
	bonus/rendering/3d_bonus.c bonus/rendering/minimap_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

$(NAME) : $(OBJ) mandatory/cub3d.h
	cc $(OBJ) $(DEPENDECES) -Iinclude -lglfw  -L$(GLFW) $(MLXLIB) -fsanitize=address -g -o $(NAME)

$(NAMEB) : $(OBJB) bonus/cub3d_bonus.h
	cc $(OBJB) $(DEPENDECES) -Iinclude -lglfw  -L$(GLFW) $(MLXLIB) -fsanitize=address -g -o $(NAMEB)

all : $(NAME)

bonus : $(NAMEB)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME) $(NAMEB)

re : fclean all bonus
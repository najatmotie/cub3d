NAME = cub3D

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror 

SRC = main.c libft_utils.c map_utils.c events.c drawing.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) cub3d.h
	cc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


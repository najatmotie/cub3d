# include "mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define TILE_SIZE 64

typedef struct s_mlx
{
    void *mlx;
    void *win;
} t_mlx;

typedef struct s_player
{
    int p_x;
    int p_y;
    char p_dir;
} t_player;

typedef struct s_cub
{
    char **map;
    t_mlx mlx;
    t_player player;
} t_cub;


size_t	ft_strlen(const char *s);
void    get_map_size(char *file, int *width, int *height);
char    **fill_map(char *file, int width, int height, t_cub *cub);
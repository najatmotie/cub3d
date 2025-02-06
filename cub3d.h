# include "mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>

#define TILE_SIZE 64
#define ESC_KEY 53
#define W_KEY   13
#define A_KEY   0 
#define S_KEY   1 
#define D_KEY   2 

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
} t_mlx;

typedef struct s_ply
{
    double p_x;
    double p_y;
    // char p_dir;
    int dir_x;
    int dir_y;
} t_ply;

typedef struct s_cub
{
    char **map;
    t_mlx mlx;
    t_ply ply;
} t_cub;

size_t	ft_strlen(const char *s);
void    ft_free(char **map);
void    get_map_size(char *file, int *width, int *height);
char    **fill_map(char *file, int width, int height, t_cub *cub);
int close_window(t_cub *cub);
int key_hook(int keycode, t_cub *cub);
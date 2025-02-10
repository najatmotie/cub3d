# include "mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>

#define A_KEY 0 
#define S_KEY 1 
#define D_KEY 2 
#define W_KEY 13
#define ESC_KEY 53
#define LEFT_ARROW 123
#define RIGHT_ARROW 124
#define FOV 60
#define TILE_SIZE 50
#define PLANE_LENGTH (tan(FOV * M_PI / 360.0)) // Convert (FOV / 2) to radians (radians = degrees * π / 180 (π = 3.14))

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
} t_mlx;

typedef struct s_ply
{
    double pos_x;
    double pos_y;
    int dir_x;
    int dir_y;
    double plane_x;
    double plane_y;
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
void    draw_map(void *mlx_ptr, void *win_ptr);
void    draw_player(void *mlx_ptr, void *win_ptr, t_ply player);

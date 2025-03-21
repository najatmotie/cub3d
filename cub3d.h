#ifndef CUB3D_H
#define CUB3D_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>

// #define π 3.14
// #define PLANE_LENGTH (tan(FOV * M_PI / 360.0)) // Convert (FOV / 2) to radians (radians = degrees * π / 180 (π = 3.14))

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MINIMAP_SCALE 5
#define FOV 60
#define TILE 50
// #define TILE 10

extern int Map[MAP_HEIGHT][MAP_WIDTH];

typedef struct s_mlx
{
    mlx_t *mlx_ptr;
    mlx_image_t* img_ptr;
} t_mlx;

typedef struct s_map
{
    int width;
    int height;
    char **map;
} t_map;

// typedef struct s_point
// {
//     float x;
//     float y;
//     int distance;
// } t_point;

typedef struct s_ray
{
    float end_x;
    float end_y;
    float distance;
} t_ray;

typedef struct s_ply
{
    float pos_x;
    float pos_y;
    float angle;
} t_ply;

typedef struct s_cub
{
    t_map map;
    t_mlx mlx;
    t_ply ply;
    t_ray *ray;
} t_cub;

size_t	ft_strlen(const char *s);
void    ft_free(char **map);
void    get_map_size(char *file, int *width, int *height);
// char    **fill_map(char *file, int width, int height, t_cub *cub);
// int close_window(t_cub *cub);
void key_hook(void *param);
void    draw_minimap(t_cub *cub);
void    draw_player(t_cub *cub);
// void DDA(t_cub *cub, float X0, float Y0, float X1, float Y1);
void    cast_all_rays(t_cub *cub);
int inside_bounds(float x, float y);
int normalize_angle(int angle);

#endif
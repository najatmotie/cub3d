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

#define FOV 60
#define TILE 40
// #define MAP_WIDTH 16
// #define MAP_HEIGHT 12
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 0.5
#define ROTATION_SPEED 1
#define MINIMAP 0.4
#define MOUSE_SENSITIVITY 0.5

// extern int Map[MAP_HEIGHT][MAP_WIDTH];

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

typedef struct s_ray
{
    float end_x;
    float end_y;
    float distance;
    float ray_angle;
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
void    get_map_size(char *file, t_cub *cub);
char    **fill_map(char *file, t_cub *cub);
void key_hook(void *param);
void    draw_minimap(t_cub *cub);
void    draw_player(t_cub *cub);
void    cast_all_rays(t_cub *cub);
int inside_bounds(t_cub *cub, float x, float y);
float normalize_angle(float angle);
float degree_to_radian(float angle);
void draw_wall(t_cub *cub, int index, int color);
void DDA(t_cub *cub, float X0, float Y0, float X1, float Y1) ;
float calculate_distance(float x1, float y1, float x2, float y2);
void	check_errors(t_cub cub, int width, int height);

#endif
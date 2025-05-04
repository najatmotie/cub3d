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
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 0.5
#define ROTATION_SPEED 1
#define MINIMAP 0.4

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
    float ply_angle;
} t_ply;

typedef struct s_textures
{
    char *north_path;
    char *north_image;
    char *south_path;
    char *south_image;
    char *west_path;
    char *west_image;
    char *east_path;
    char *east_image;
} t_textures;

typedef struct s_colors
{
    int floor_color;
    int ceiling_color;
} t_colors;

typedef struct s_elements
{
    int NO;
    int SO;
    int WE;
    int EA;
    int F;
    int C;
    int N;
    int S;
    int W;
    int E;
} t_elements;

typedef struct s_cub
{
    t_map map;
    t_mlx mlx;
    t_ply ply;
    t_ray *ray;
    t_textures texters;
    t_colors colors;
    t_elements elements;
} t_cub;

void	check_file(char *file);
int open_file(char *file);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char **ft_split(char *s, char c);
void    ft_free(char **map);
void    get_map_size(char *file, t_cub *cub);
char*    parse_textures(int fd, char *line, t_cub *cub);
void    parse_map(int fd, char *line, t_cub *cub);
void    parsing_file(t_cub *cub, char *file);
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
void	check_errors(t_cub *cub);
int check_info_of_player(t_cub *cub, int i, int j);
void check_elements(t_cub *cub);
bool parse_paths(char **s, t_cub *cub);
bool    parse_colors(char *line, char **s, t_cub *cub);

#endif
#ifndef CUB3D_H
#define CUB3D_H


#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define FOV 60
#define TILE 50
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 0.1
#define ROTATION_SPEED 1

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
    char **map;
    int height;
    int width;
} t_map;

typedef struct s_ray
{
    float wall_hit_x;
    float wall_hit_y;
    float ray_angle;
    char wall_side;
    float distance_to_wall;
} t_ray;

typedef struct s_ply
{
    float ply_x;
    float ply_y;
    float ply_angle;
} t_ply;

typedef struct s_texture
{
    uint32_t floor_color;
    uint32_t ceiling_color;
    mlx_texture_t* north_texture;
    mlx_texture_t* south_texture;
    mlx_texture_t* west_texture;
    mlx_texture_t* east_texture;
} t_texture;

typedef struct s_elements
{
    int F;
    int C;
    int NO;
    int SO;
    int WE;
    int EA;
    int N;
    int S;
    int W;
    int E;
} t_elements;

typedef struct s_dda
{
    float start_x;
    float start_y;
    float end_x;
    float end_y;
    int distance_x;
    int distance_y;
    int pixels_steps;
} t_dda;

typedef struct s_cub
{
    t_map map;
    t_mlx mlx;
    t_ply ply;
    t_ray *ray;
    t_dda dda;
    t_texture textures;
    t_elements elements;
} t_cub;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char **ft_split(char *s, char c);

void    init_data(t_cub *cub);
void    double_free(char **map);
void    free_ressources(char *line, char **s, char **colors);
void    cleanup_ressources(t_cub *cub);

int open_file(char *file);
void    get_map_size(char *file, t_cub *cub);
void	check_file(char *file);
char *remove_newline(char *path);
char*    parse_textures(int fd, char *line, t_cub *cub);
void    parse_map(int fd, char *line, t_cub *cub);
void    parsing_file(t_cub *cub, char *file);
void	check_errors(t_cub *cub);
int check_info_of_player(t_cub *cub, int i, int j);
void check_elements(t_cub *cub);
bool parse_paths(char **s, t_cub *cub);
bool    parse_colors(char *line, char **s, t_cub *cub);

void forward_move(t_cub *cub);
void    backward_move(t_cub *cub);
void    left_move(t_cub *cub);
void    right_move(t_cub *cub);
void    esc_key(t_cub *cub);

void draw_3d(t_cub *cub, int x);
void DDA(t_cub *cub, t_dda dda);

int inside_bounds(t_cub cub, float x, float y);
int screen_bounds(float x, float y);
float normalize_angle(float angle);
float degree_to_radian(float angle);
float calculate_distance(float x1, float y1, float x2, float y2);
t_ray get_horisontal(t_cub *cub, float ray_angle);
t_ray get_vertical(t_cub *cub, float ray_angle);
t_ray shortest_distance(t_ray a, t_ray b);
void    cast_rays(t_cub *cub);
void game_loop(void *param);

#endif
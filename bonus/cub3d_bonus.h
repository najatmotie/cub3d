/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:11 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 12:45:40 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define FOV 60
# define TILE 50
# define MINIMAP 0.5
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 1
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1280

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_mlx
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*img_ptr;
}					t_mlx;

typedef struct s_map
{
	char			**map;
	int				height;
	int				width;
}					t_map;

typedef struct s_ray
{
	float			wall_hit_x;
	float			wall_hit_y;
	float			ray_angle;
	char			wall_side;
	float			distance_to_wall;
}					t_ray;

typedef struct s_ply
{
	float			ply_x;
	float			ply_y;
	float			ply_angle;
}					t_ply;

typedef struct s_texture
{
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}					t_texture;

typedef struct s_elements
{
	int				f;
	int				c;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				n;
	int				s;
	int				w;
	int				e;
}					t_elements;

typedef struct s_dda
{
	float			start_x;
	float			start_y;
	float			end_x;
	float			end_y;
	int				distance_x;
	int				distance_y;
	int				pixels_steps;
}					t_dda;

typedef struct s_cub
{
	t_map			map;
	t_mlx			mlx;
	t_ply			ply;
	t_ray			*ray;
	t_dda			dda;
	t_texture		textures;
	t_elements		elements;
}					t_cub;

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(const char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s1);
char				**ft_split(char *s, char c);

int					open_file(char *file);
void				get_map_size(char *file, t_cub *cub);
void				check_file(char *file);
char				*remove_newline(char *path);
char				*parse_textures(int fd, char *line, t_cub *cub);
void				parse_map(t_cub *cub, char *line, int fd);
void				parsing_file(t_cub *cub, char *file);
void				check_errors(t_cub *cub);
int					check_info_of_player(t_cub *cub, int i, int j);
bool				parse_paths(char **s, t_cub *cub);
bool				parse_colors(char *line, char **s, t_cub *cub);
void				free_ressources(t_cub *cub, char *line, char **s,
						char **colors);

bool				can_move(t_cub cub, int x, int y);
void				init_data(t_cub *cub);
void				double_free(char **map);
void				cleanup_ressources(t_cub *cub);
void				my_mlx_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
						uint32_t color);

void				esc_key(t_cub *cub);
void				forward_move(t_cub *cub);
void				backward_move(t_cub *cub);
void				left_move(t_cub *cub);
void				right_move(t_cub *cub);

float				normalize_angle(float angle);
float				degree_to_radian(float angle);
float				calculate_distance(float x1, float y1, float x2, float y2);
bool				check_wall(t_cub cub, int x, int y, float angle);
int					inside_bounds(t_cub cub, float x, float y);
t_ray				get_horisontal(t_cub *cub, float ray_angle);
t_ray				get_vertical(t_cub *cub, float ray_angle);
void				cast_rays(t_cub *cub);
void				game_loop(void *param);

void				draw_3d(t_cub *cub, int x);
void				draw_minimap(t_cub *cub);

#endif
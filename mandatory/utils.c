#include "cub3d.h"

void    init_data(t_cub *cub)
{
    cub->elements.C = 0;
    cub->elements.E = 0;
    cub->elements.EA = 0;
    cub->elements.F = 0;
    cub->elements.N = 0;
    cub->elements.NO = 0;
    cub->elements.C = 0;
    cub->elements.F = 0;
    cub->elements.SO = 0;
    cub->elements.WE = 0;
}

void    double_free(char **map)
{
    int i = 0;

    while(map && map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    map = NULL;
}
void    free_ressources(char *line, char **s, char **colors)
{
    free(line);
    double_free(s);
    double_free(colors);
    write(2, "Error!\n", 7);
    exit(1);
}

void    cleanup_ressources(t_cub *cub)
{
    free(cub->ray);
    double_free(cub->map.map);
    if(cub->textures.north_texture)
        mlx_delete_texture(cub->textures.north_texture);
    if(cub->textures.south_texture)
        mlx_delete_texture(cub->textures.south_texture);
    if(cub->textures.west_texture)
        mlx_delete_texture(cub->textures.west_texture);
    if(cub->textures.east_texture)
        mlx_delete_texture(cub->textures.east_texture);
    mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	mlx_close_window(cub->mlx.mlx_ptr);
}

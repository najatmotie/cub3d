#include "../../cub3d.h"

bool    north_image(t_cub *cub, char *path)
{
    cub->elements.NO++;
    cub->textures.north_texture = mlx_load_png(path);
    if (!cub->textures.north_texture)
    {
        printf("%s\n", mlx_strerror(mlx_errno));
        exit(1);
    }
    return true;
}

bool    south_image(t_cub *cub, char *path)
{
    cub->elements.SO++;
    cub->textures.south_texture = mlx_load_png(path);
    if (!cub->textures.south_texture)
    {
        printf("%s\n", mlx_strerror(mlx_errno));
        exit(1);
    }
    return true;
}

bool    west_image(t_cub *cub, char *path)
{
    cub->elements.WE++;
    cub->textures.west_texture = mlx_load_png(path);
    if (!cub->textures.west_texture)
    {
        printf("%s\n", mlx_strerror(mlx_errno));
        exit(1);
    }
    return true;
}

bool    east_image(t_cub *cub, char *path)
{
    cub->elements.EA++;
    cub->textures.east_texture = mlx_load_png(path);
    if (!cub->textures.east_texture)
    {
        printf("%s\n", mlx_strerror(mlx_errno));
        exit(1);
    }
    return true;
}

bool parse_paths(char **s, t_cub *cub)
{
    if(s[0] && s[1] && ft_strcmp(s[0], "NO") == 0)
    {
        if(!north_image(cub, remove_newline(s[1])))
            return (false);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "SO") == 0)
    {
        if(!south_image(cub, remove_newline(s[1])))
            return (false);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "WE") == 0)
    {
        if(!west_image(cub, remove_newline(s[1])))
            return (false);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "EA") == 0)
    {
        if(!east_image(cub, remove_newline(s[1])))
            return (false);
        return true;
    }
   return false;
}

#include "../../cub3d.h"

bool    floor_color(char *line, char **s, t_cub *cub)
{
    int r;
    int g;
    int b;
    char **colors;

    if(s[0] && s[1] && ft_strcmp(s[0], "F") == 0)
    {
        colors = ft_split(s[1], ',');
        if(colors[0] && colors[1] && colors[2] && !colors[3])
        {
            r = ft_atoi(colors[0]);
            g = ft_atoi(colors[1]);
            b = ft_atoi(colors[2]);
            if((r < 0 && r > 255) || (g < 0 && g > 255) || (b < 0 && b > 255))
                free_ressources(line, s, colors);
            double_free(colors);
            cub->elements.F++;
            cub->textures.floor_color = (r << 16) | (g << 8) | b;
            return true;
        }
        else
            free_ressources(line, s, colors);
    }
    return false;
}

bool    ceiling_color(char *line, char **s, t_cub *cub)
{
    int r;
    int g;
    int b;
    char **colors;

    if(s[0] && s[1] && ft_strcmp(s[0], "C") == 0)
    {
        colors = ft_split(s[1], ',');
        if(colors[0] && colors[1] && colors[2] && !colors[3])
        {
            r = ft_atoi(colors[0]);
            g = ft_atoi(colors[1]);
            b = ft_atoi(colors[2]);;
            if((r < 0 && r > 255) || (g < 0 && g > 255) || (b < 0 && b > 255))
                free_ressources(line, s, colors);
            double_free(colors);
            cub->elements.C++;
            cub->textures.ceiling_color = (r << 16) | (g << 8) | b;
            return true;
        }
        else
            free_ressources(line, s, colors);
    }
    return false;
}

bool    parse_colors(char *line, char **s, t_cub *cub)
{
    if(!floor_color(line, s, cub) && !ceiling_color(line, s, cub))
        return false;
    return true;
}

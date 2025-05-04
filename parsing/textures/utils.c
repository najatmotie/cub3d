#include "../../cub3d.h"

bool parse_paths(char **s, t_cub *cub)
{
    if(s[0] && s[1] && ft_strcmp(s[0], "NO") == 0)
    {
        cub->elements.NO++;
        cub->texters.north_path = ft_strdup(s[1]);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "SO") == 0)
    {
        cub->elements.SO++;
        cub->texters.south_path = ft_strdup(s[1]);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "WE") == 0)
    {
        cub->elements.WE++;
        cub->texters.west_path = ft_strdup(s[1]);
        return true;
    }
    else if(s[0] && s[1] && ft_strcmp(s[0], "EA") == 0)
    {
        cub->elements.EA++;
        cub->texters.east_path = ft_strdup(s[1]);
        return true;
    }
   return false;
}

bool    floor_color(char *line, char **s, t_cub *cub)
{
    if(s[0] && s[1] && ft_strcmp(s[0], "F") == 0)
    {
        char **colors = ft_split(s[1], ',');
        if(colors[0] && colors[1] && colors[2] && !colors[3])
        {
            int r = ft_atoi(colors[0]);
            int g = ft_atoi(colors[1]);
            int b = ft_atoi(colors[2]);;
            if((r < 0 && r > 255) || (g < 0 && g > 255) || (b < 0 && b > 255))
            {
                free(line);
                ft_free(s);
                ft_free(colors);
                write(2, "Error!\n", 7);
                exit(1);
            }
            ft_free(colors);
            cub->elements.F++;
            cub->colors.floor_color = (r << 16) | (g << 8) | b;
            return true;
        }
        else
        {
            free(line);
            ft_free(s);
            ft_free(colors);
            write(2, "Error!\n", 7);
            exit(1);
        }
    }
    return false;
}

bool    ceiling_color(char *line, char **s, t_cub *cub)
{
    if(s[0] && s[1] && ft_strcmp(s[0], "C") == 0)
    {
        char **colors = ft_split(s[1], ',');
        if(colors[0] && colors[1] && colors[2] && !colors[3])
        {
            int r = ft_atoi(colors[0]);
            int g = ft_atoi(colors[1]);
            int b = ft_atoi(colors[2]);;
            if((r < 0 && r > 255) || (g < 0 && g > 255) || (b < 0 && b > 255))
            {
                free(line);
                ft_free(s);
                ft_free(colors);
                write(2, "Error!\n", 7);
                exit(1);
            }
            ft_free(colors);
            cub->elements.C++;
            cub->colors.ceiling_color = (r << 16) | (g << 8) | b;
            return true;
        }
        else
        {
            free(line);
            ft_free(s);
            ft_free(colors);
            write(2, "Error!\n", 7);
            exit(1);
        }
    }
    return false;
}

bool    parse_colors(char *line, char **s, t_cub *cub)
{
    if(!floor_color(line, s, cub) && !ceiling_color(line, s, cub))
        return false;
    return true;
}

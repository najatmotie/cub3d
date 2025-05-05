#include "../../cub3d.h"

void check_elements(t_cub *cub)
{
    if(cub->elements.NO != 1 || cub->elements.SO != 1 || cub->elements.WE != 1 || cub->elements.EA != 1
        || cub->elements.F != 1 || cub->elements.C != 1)
    {
        write(2, "Error!\n", 7);
		exit(1);
    }
}

char*    parse_textures(int fd, char *line, t_cub *cub)
{
    while (1)
    {
        line = get_next_line(fd);
        if((!line || ft_strchr(line, '0') || ft_strchr(line, '1')) && !ft_strchr(line, ','))
            break ;
        char **s = ft_split(line, ' ');
        if((!s[0] && !s[1]) || (ft_strcmp(s[0], "\n") == 0 && !s[1]))
            continue ;
        if(!parse_paths(s, cub) && !parse_colors(line, s, cub))
        {
            free(line);
            ft_free(s);
            write(2, "Error!\n", 7);
            exit(1);
        }
        else
        {
            free(line);
            ft_free(s);
        }
    }
    check_elements(cub);
    return (line);
}

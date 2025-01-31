#include "../cub3d.h"

void    get_map_size(char *file, int *width, int *height)
{
    char buffer;
    int fix_width;

    *height = 1;
    fix_width = 0;
    int fd = open(file, O_RDONLY);

    if(fd < 0)
    {
        perror(file);
        exit(1);
    }
    while (read(fd, &buffer, 1) > 0)
    {
        if(buffer == '\n')
        {
            (*height)++;
            fix_width = *width;
            *width = 0;
        }
        else
            (*width)++;
    }
    close(fd);
    *width = fix_width;
}

char    **fill_map(char *file, int width, int height, t_cub *cub)
{
    int i;
    int j;
    int fd;
    char buffer;
    bool eof;

    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        perror(file);
        exit(1);
    }
    i = 0;
    eof = false;
    char **map = malloc((height + 1) * sizeof(char));
    while(1)
    {
        j = 0;
        map[i] = malloc(width + 1);
        if(eof)
            break;
        while (1)
        {
            if(!read(fd, &buffer, 1))
            {
                eof = true;
                break;
            }
            if(buffer == '\n')
            {
                map[i][j] = '\0';
                break;
            }
            if(buffer == 'N' || buffer == 'E' || buffer == 'S' || buffer == 'W')
            {
                cub->player.p_x = j;
                cub->player.p_y = i;
                cub->player.p_dir = buffer;
            }
            map[i][j] = buffer;
            j++;
        }
        i++;
        // if(eof)
        //     break;
    }
    close(fd);
    map[i] = NULL;
    return(map);
}

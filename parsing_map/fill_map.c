#include "../cub3d.h"

void    get_map_size(char *file, t_cub *cub)
{
    char buffer;
    int fix_width;

    cub->map.height = 1;
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
            (cub->map.height)++;
            if(fix_width < cub->map.width)
                fix_width = cub->map.width;
            cub->map.width = 0;
        }
        else
            (cub->map.width)++;
    }
    close(fd);
    cub->map.width = fix_width;
}

char    **fill_map(char *file, t_cub *cub)
{
    int i;
    int j;
    int fd;
    bool eof;
    char buffer;

    get_map_size(file, cub);
    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        perror(file);
        exit(1);
    }
    i = 0;
    eof = false;
    // printf("-->%d\n", cub->map.height);
    char **map = malloc((cub->map.height + 1) * sizeof(char *));
    while(1)
    {
        j = 0;
        map[i] = malloc(cub->map.width + 1);
        if(eof)
            break;
        while (1)
        {
            if(!read(fd, &buffer, 1))
            {
                eof = true;
                if(j < cub->map.width)
                {
                    while(j < cub->map.width)
                    {
                        map[i][j] = ' ';
                        j++;
                    } 
                }
                map[i][j] = '\0';
                break;
            }
            if(buffer == '\n')
            {
                if(j < cub->map.width)
                {
                    while(j < cub->map.width)
                    {
                        map[i][j] = ' ';
                        j++;
                    } 
                }
                map[i][j] = '\0';
                break;
            }
            if(buffer == 'N')
            {
                cub->ply.pos_x = j;
                cub->ply.pos_y = i;
                cub->ply.angle = 90;
            }
            if(buffer == 'E')
            {
                cub->ply.pos_x = j;
                cub->ply.pos_y = i;
                cub->ply.angle = 0;
            }
            if(buffer == 'S')
            {
                cub->ply.pos_x = j;
                cub->ply.pos_y = i;
                cub->ply.angle = 270;
            }
            if(buffer == 'W')
            {
                cub->ply.pos_x = j;
                cub->ply.pos_y = i;
                cub->ply.angle = 180;
            }
            map[i][j] = buffer;
            j++;
        }
        // printf("%s\n", map[i]);
        i++;
    }
    close(fd);
    map[i] = NULL;
    return(map);
}

#include "../../cub3d.h"

void handle_first_line(t_cub *cub, char *line, char **map)
{
    int j = 0;

    if(line)
    {
        while(line[j] != '\n' && line[j] != '\0')
        {
            map[0][j] = line[j];
            j++;
        }
        if(j < cub->map.width)
        {
            while(j < cub->map.width)
            {
                map[0][j] = ' ';
                j++;
            } 
        }
        if(j < cub->map.width)
        {
            while(j < cub->map.width)
            {
                cub->map.map[0][j] = ' ';
                j++;
            } 
        }
        map[0][j] = '\0';
    }
}

void    fill_map(int fd, int *eof, int i, t_cub *cub)
{
    int j = 0;
    char* line;

    while (1)
    {
        line = get_next_line(fd);
        if(!line)
        {
            free(line);
            *eof = true;
            break ;
        }
        else
        {
            while (line[j] != '\n' && line[j] != '\0')
            {
                cub->map.map[i][j] = line[j];
                j++;
            }
            free(line);
            if(j < cub->map.width)
            {
                while(j < cub->map.width)
                {
                    cub->map.map[i][j] = ' ';
                    j++;
                } 
            }
            cub->map.map[i][j] = '\0';
            break ;
        }
    }
}

void    parse_map(int fd, char *line, t_cub *cub)
{
    int i;
    int eof;

    i = 0;
    eof = false;
    cub->map.map = malloc((cub->map.height + 1) * sizeof(char *));
    while(1)
    {
        cub->map.map[i] = malloc(cub->map.width + 1);
        if(line)
        {
            handle_first_line(cub, line, cub->map.map);
            free(line);
            line = NULL;
            i++;
            continue ;
        }
        fill_map(fd, &eof, i, cub);
        if(eof)
            break ;
        i++;
    }
    close(fd);
    cub->map.map[i] = NULL;
    check_errors(cub);
}

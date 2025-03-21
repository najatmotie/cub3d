#include "cub3d.h"

void    ft_free(char **map)
{
    int i = 0;

    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    map = NULL;
}

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

// char    **fill_map(char *file, int width, int height, t_cub *cub)
// {
//     int i;
//     int j;
//     int fd;
//     char buffer;
//     bool eof;

//     fd = open(file, O_RDONLY);
//     if(fd < 0)
//     {
//         perror(file);
//         exit(1);
//     }
//     i = 0;
//     eof = false;
//     char **map = malloc((height + 1) * sizeof(char));
//     while(1)
//     {
//         j = 0;
//         map[i] = malloc(width + 1);
//         if(eof)
//             break;
//         while (1)
//         {
//             if(!read(fd, &buffer, 1))
//             {
//                 eof = true;
//                 break;
//             }
//             if(buffer == '\n')
//             {
//                 map[i][j] = '\0';
//                 break;
//             }
//             if(buffer == 'N')
//             {
//                 cub->ply.pos_x = j;
//                 cub->ply.pos_y = i;
//                 cub->ply.dir_x = 0;
//                 cub->ply.dir_y = -1;
//                 cub->ply.plane_x = PLANE_LENGTH;
//                 cub->ply.plane_y = 0;
//             }
//             if(buffer == 'E')
//             {
//                 cub->ply.pos_x = j;
//                 cub->ply.pos_y = i;
//                 cub->ply.dir_x = 1;
//                 cub->ply.dir_y = 0;
//                 cub->ply.plane_x = 0;
//                 cub->ply.plane_y = -PLANE_LENGTH;
//             }
//             if(buffer == 'S')
//             {
//                 cub->ply.pos_x = j;
//                 cub->ply.pos_y = i;
//                 cub->ply.dir_x = 0;
//                 cub->ply.dir_y = 1;
//                 cub->ply.plane_x = -PLANE_LENGTH;
//                 cub->ply.plane_y = 0;
//             }
//             if(buffer == 'W')
//             {
//                 cub->ply.pos_x = j;
//                 cub->ply.pos_y = i;
//                 cub->ply.dir_x = -1;
//                 cub->ply.dir_y = 0;
//                 cub->ply.plane_x = 0;
//                 cub->ply.plane_y = PLANE_LENGTH;
//             }
//             map[i][j] = buffer;
//             j++;
//         }
//         i++;
//         // if(eof)
//         //     break;
//     }
//     close(fd);
//     map[i] = NULL;
//     return(map);
// }

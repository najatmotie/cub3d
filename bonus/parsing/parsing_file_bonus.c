#include "../cub3d_bonus.h"

int open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        perror(file);
        exit(1);
    }
    return (fd);
}

void    parsing_file(t_cub *cub, char *file)
{
    int fd;
    char *line;

    line = NULL;
    get_map_size(file, cub);
    fd = open_file(file);
    line = parse_textures(fd, line, cub);
    parse_map(fd, line, cub);
}

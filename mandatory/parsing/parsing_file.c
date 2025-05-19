#include "../cub3d.h"

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
    // if(cub->map.width * TILE > SCREEN_WIDTH || cub->map.height * TILE > SCREEN_HEIGHT)
    // {
    //     write(2, "size of map greater than size of screen!\n", ft_strlen("size of map greater than size of screen!\n"));
	// 	exit(1);
    // }
    fd = open_file(file);
    line = parse_textures(fd, line, cub);
    parse_map(fd, line, cub);
}

#include "cub3d.h"
#define TILE_SIZE 64

void    get_map_size(char *file, int *width, int *height)
{
    char buffer;
    int fix_width = 0;
    int fd = open(file, O_RDONLY);

    if(fd < 0)
    {
        perror(file);
        return ;
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

int main(int ac, char **av)
{
    int width = 0;
    int height = 0;
    t_cub cub;


    if(ac == 2)
    {
        cub.mlx = mlx_init();
        get_map_size(av[1], &width, &height);
        cub.win = mlx_new_window(cub.mlx, width * TILE_SIZE, height * TILE_SIZE, "cub3D");
        mlx_loop(cub.mlx);
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}

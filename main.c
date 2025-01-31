#include "cub3d.h"

int main(int ac, char **av)
{
    int width;
    int height;
    t_cub cub;


    if(ac == 2)
    {
        cub.mlx.mlx = mlx_init();
        get_map_size(av[1], &width, &height);
        // printf("%d %d\n", width, height);
        cub.map = fill_map(av[1], width, height, &cub);
        // printf("here\n");
        // int i = 0;
        // while(cub.map[i])
        // {
        //     printf("%s\n", cub.map[i]);
        //     i++;
        // }
        cub.mlx.win = mlx_new_window(cub.mlx.mlx, width * TILE_SIZE, height * TILE_SIZE, "cub3D");
        mlx_loop(cub.mlx.mlx);
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}

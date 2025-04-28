#include "cub3d.h"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        t_cub cub;
        cub.ray = malloc(SCREEN_WIDTH * sizeof(t_ray));
        cub.map.map = fill_map(av[1], &cub);
        check_errors(cub, cub.map.width, cub.map.height);
        for(int i = 0; i < cub.map.height; i++)
            printf("%s\n", cub.map.map[i]);
        // cub.mlx.mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", 0);
        // mlx_loop_hook(cub.mlx.mlx_ptr, key_hook, &cub);
        // mlx_loop(cub.mlx.mlx_ptr);     
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}

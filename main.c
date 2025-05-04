#include "cub3d.h"

void    init_data(t_cub *cub)
{
    cub->texters.east_path = NULL;
    cub->texters.north_path = NULL;
    cub->texters.south_path = NULL;
    cub->texters.west_path = NULL;
    cub->elements.C = 0;
    cub->elements.E = 0;
    cub->elements.EA = 0;
    cub->elements.F = 0;
    cub->elements.N = 0;
    cub->elements.NO = 0;
    cub->elements.C = 0;
    cub->elements.F = 0;
    cub->elements.SO = 0;
    cub->elements.WE = 0;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        t_cub cub;
        check_file(av[1]);
        init_data(&cub);
        parsing_file(&cub, av[1]);
        // cub.ray = malloc(SCREEN_WIDTH * sizeof(t_ray));
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

#include "cub3d_bonus.h"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        t_cub cub;
        check_file(av[1]);
        init_data(&cub);
        parsing_file(&cub, av[1]);
        cub.ray = malloc(SCREEN_WIDTH * sizeof(t_ray));
        cub.mlx.mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", 0);
        mlx_loop_hook(cub.mlx.mlx_ptr, game_loop, &cub);
        mlx_loop(cub.mlx.mlx_ptr);     
        cleanup_ressources(&cub);
        mlx_terminate(cub.mlx.mlx_ptr);
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}

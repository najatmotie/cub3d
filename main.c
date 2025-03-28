#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub cub;

    (void)av;
    (void)ac;
    // if(ac == 2)
    // {
        t_ply player = {1.5 * TILE*MINIMAP, 1.5 * TILE*MINIMAP, 90};
        cub.ply = player;
        cub.ray = malloc(SCREEN_WIDTH * sizeof(t_ray));
        cub.mlx.mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", 0);
        mlx_loop_hook(cub.mlx.mlx_ptr, key_hook, &cub);        
        mlx_loop(cub.mlx.mlx_ptr);     
    // }
    // else
    // {
    //     write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
    //     return(1);
    // }
    return(0);
}

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub cub;

    (void)av;
    (void)ac;
    // if(ac == 2)
    // {
        t_ply player = {1.5 * 50, 1.5 * 50, 90};
        cub.ply = player;
        cub.ray = malloc(MAP_WIDTH * TILE * sizeof(t_ray));
        cub.mlx.mlx_ptr = mlx_init(MAP_WIDTH * TILE, MAP_HEIGHT * TILE, "cub3D", 0);
        cub.mlx.img_ptr = mlx_new_image(cub.mlx.mlx_ptr, MAP_WIDTH * TILE, MAP_HEIGHT * TILE);
        mlx_image_to_window(cub.mlx.mlx_ptr, cub.mlx.img_ptr, 0, 0);

        mlx_loop_hook(cub.mlx.mlx_ptr, key_hook, &cub);        
        // draw_map(&cub);
        // draw_player(&cub);
        mlx_loop(cub.mlx.mlx_ptr);     
    // }
    // else
    // {
    //     write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
    //     return(1);
    // }
    return(0);
    // printf("cos %f sin %f\n", cos(6.30064), cos(0.0174533));
}

#include "cub3d.h"

int main(int ac, char **av)
{
    // int width;
    // int height;
    t_cub cub;

    (void)av;
    if(ac == 2)
    {
        t_ply player = {1.5, 1.5, -1, 0, 0, PLANE_LENGTH};
        cub.ply = player;
        cub.mlx.mlx_ptr = mlx_init();
        // cub.mlx.mlx = mlx_init(cub.mlx.mlx, width * TILE_SIZE, height * TILE_SIZE, "cub3D", 0);
        // get_map_size(av[1], &width, &height);
        // cub.map = fill_map(av[1], width, height, &cub);
        cub.mlx.win_ptr = mlx_new_window(cub.mlx.mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "cub3D");
        // mlx_key_hook(cub.mlx.win_ptr, key_hook, &cub);
        mlx_hook(cub.mlx.win_ptr, 2, 0, key_hook, &cub);
        // mlx_hook(cub.mlx.win_ptr, 3, 0, key_hook, &cub);
        mlx_hook(cub.mlx.win_ptr, 17, 0, close_window, &cub);
        // mlx_pixel_put(cub.mlx.mlx_ptr, cub.mlx.win_ptr, 400, 300, 0xFF0000);
        draw_map(cub.mlx.mlx_ptr, cub.mlx.win_ptr);
        draw_player(cub.mlx.mlx_ptr, cub.mlx.win_ptr, cub.ply);
        mlx_loop(cub.mlx.mlx_ptr);
        
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}

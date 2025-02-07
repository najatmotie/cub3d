#include "../cub3d.h"

int close_window(t_cub *cub)
{
    printf("Window Closed!\n");
    mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    exit(0);
}

int key_hook(int keycode, t_cub *cub)
{
    if(keycode == ESC_KEY)
    {
        printf("ESC pressed!\n");
        mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
        exit(0);
    }
    return(0);
}
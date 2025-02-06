#include "../cub3d.h"

int close_window(t_cub *cub)
{
    mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    printf("Window Closed\n");
    exit(0);
}

int key_hook(int keycode, t_cub *cub)
{
    if(keycode == ESC_KEY)
    {
        mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
        exit(0);
    }
    return(0);
}
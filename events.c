#include "cub3d.h"

int close_window(t_cub *cub)
{
    printf("Window Closed!\n");
    mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    exit(0);
}

int key_hook(int keycode, t_cub *cub)
{
    double move_speed = 0.1;

    // printf("keycode: %d\n", keycode);
    if(keycode == ESC_KEY)
    {
        printf("ESC pressed!\n");
        mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
        exit(0);
    }
    if(keycode == W_KEY)
    {
        cub->ply.pos_x += cub->ply.dir_x * move_speed;
        cub->ply.pos_y += cub->ply.dir_y * move_speed;
    }
    if(keycode == S_KEY)
    {
        cub->ply.pos_x -= cub->ply.dir_x * move_speed;
        cub->ply.pos_y -= cub->ply.dir_y * move_speed;
    }
    if(keycode == D_KEY)
    {
        cub->ply.pos_x += cub->ply.dir_y * move_speed;
        cub->ply.pos_y -= cub->ply.dir_x * move_speed;
    }
    if(keycode == A_KEY)
    {
        cub->ply.pos_x -= cub->ply.dir_y * move_speed;
        cub->ply.pos_y += cub->ply.dir_x * move_speed;
    }
    // printf("pos_x: %f pos_y: %f\n", cub->ply.pos_x, cub->ply.pos_y);
    mlx_clear_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    draw_map(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    draw_player(cub->mlx.mlx_ptr, cub->mlx.win_ptr, cub->ply);
    return(0);
}
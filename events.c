#include "cub3d.h"

int close_window(t_cub *cub)
{
    printf("Window Closed!\n");
    mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    exit(0);
}

// x1 = x * cos(θ) - y * sin(θ)
// y1 = x * sin(θ) + y * cos(θ)

int key_hook(int keycode, t_cub *cub)
{
    double move_speed = 0.1;
    double rotation_speed = 0.1;

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
    if (keycode == 123) 
    {
        double old_dir = cub->ply.dir_x;
        cub->ply.dir_x = cub->ply.dir_x * cos(-rotation_speed) - cub->ply.dir_y * sin(-rotation_speed);
        cub->ply.dir_y = old_dir * sin(-rotation_speed) + cub->ply.dir_y * cos(-rotation_speed);

        double old_plane_x = cub->ply.plane_x;
        cub->ply.plane_x = cub->ply.plane_x * cos(-rotation_speed) - cub->ply.plane_y * sin(-rotation_speed);
        cub->ply.plane_y = old_plane_x * sin(-rotation_speed) + cub->ply.plane_y * cos(-rotation_speed);
    }
    if (keycode == 124) 
    {
        double old_dir = cub->ply.dir_x;
        cub->ply.dir_x = cub->ply.dir_x * cos(rotation_speed) - cub->ply.dir_y * sin(rotation_speed);
        cub->ply.dir_y = old_dir * sin(rotation_speed) + cub->ply.dir_y * cos(rotation_speed);

        double old_plane_x = cub->ply.plane_x;
        cub->ply.plane_x = cub->ply.plane_x * cos(rotation_speed) - cub->ply.plane_y * sin(rotation_speed);
        cub->ply.plane_y = old_plane_x * sin(rotation_speed) + cub->ply.plane_y * cos(rotation_speed);
    }
    // printf("pos_x: %f pos_y: %f\n", cub->ply.pos_x, cub->ply.pos_y);
    mlx_clear_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    draw_map(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
    draw_player(cub->mlx.mlx_ptr, cub->mlx.win_ptr, cub->ply);
    return(0);
}

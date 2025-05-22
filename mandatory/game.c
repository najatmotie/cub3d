#include "cub3d.h"

void        draw_minimap(t_cub *cub)
{
    int i = 0;
    int j = 0;
    int y = 0;
    int x = 0;
    int color;
    int screen_y;
    int screen_x;
    
    while(y < cub->map.height && y < SCREEN_HEIGHT / (TILE * 0.5))
    {
        x = 0;
        while (x < cub->map.width && x < SCREEN_WIDTH / (TILE * 0.5))
        {
            if(cub->map.map[y][x] == '1')
                color = 0x808080;
            else
                color = 0x000000;
            j = 0;
            while(j < (TILE * 0.5))
            {
                i = 0;
                while(i < TILE * 0.5)
                {
                    screen_x = x * (TILE * 0.5) + i;
                    screen_y = y * (TILE * 0.5) + j;
                    // if(screen_x >= 0 && screen_x < SCREEN_WIDTH && screen_y >= 0 && screen_y < SCREEN_HEIGHT)
                        mlx_put_pixel(cub->mlx.img_ptr, screen_x, screen_y, color);
                    i++;
                }
                j++;
            }
            x++;
        }
        y++;
    }
}

void     draw_player(t_cub *cub)
{
    int i = -4;
    int j = -4;
    int screen_x = cub->ply.ply_x * TILE * 0.5;
    int screen_y = cub->ply.ply_y * TILE * 0.5;

    while(j < 4)
    {
        i = -4;
        while(i < 4)
        {
            if(i * i + j * j <= 16)
                mlx_put_pixel(cub->mlx.img_ptr ,screen_x + j, screen_y + i, 0xFFFFFF);
            i++;
        }
        j++;
    }
    i = 0;
    cub->dda.start_x = cub->ply.ply_x * (TILE * 0.5);
    cub->dda.start_y = cub->ply.ply_y * (TILE * 0.5);
    while(i < SCREEN_WIDTH)
    {
        cub->dda.end_x = cub->ray[i].wall_hit_x * 0.5;
        cub->dda.end_y = cub->ray[i].wall_hit_y * 0.5;
        DDA(cub, cub->dda);
        i++;
    }
}

void game_loop(void *param)
{
        t_cub *cub;

        cub = (t_cub*)param;
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
                esc_key(cub);
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
                forward_move(cub);
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
                backward_move(cub);
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
                left_move(cub);
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
                right_move(cub);
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
                cub->ply.ply_angle += ROTATION_SPEED;
        if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
                cub->ply.ply_angle -= ROTATION_SPEED;
        cub->ply.ply_angle = normalize_angle(cub->ply.ply_angle);
        mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
        cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
        mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
        draw_minimap(cub);
        draw_player(cub);
        cast_rays(cub);
}

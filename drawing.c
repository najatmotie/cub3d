#include "cub3d.h"

void    draw_minimap(t_cub *cub)
{
    int color;
    int y = 0;
    int x = 0;
    int i = 0;
    int j = 0;
    int screen_y;
    int screen_x;
    
    // cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, MAP_WIDTH * TILE, MAP_HEIGHT * TILE);
    // mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
    while(y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            if(Map[y][x] == 1)
                color = 0x808080;
            else
                color = 0x000000;
            j = 0;
            while(j < TILE)
            {
                i = 0;
                while(i < TILE)
                {
                    screen_x = x * TILE + i;
                    screen_y = y * TILE + j;
                    // printf("x %d y %d\n", screen_x, screen_y);
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
    int screen_x = cub->ply.pos_x;
    int screen_y = cub->ply.pos_y;

    // cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, MAP_WIDTH * TILE, MAP_HEIGHT * TILE);
    // mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
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
}

void draw_wall()
{

}
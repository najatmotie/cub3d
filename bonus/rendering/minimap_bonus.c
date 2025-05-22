#include "../cub3d_bonus.h"

void    draw_tile(t_cub *cub, int x, int y, int color)
{
    int i;
    int j;
    int screen_y;
    int screen_x;

    j = 0;
    while(j < TILE * MINIMAP)
    {
        i = 0;
        while(i < TILE * MINIMAP)
        {
            screen_x = x * TILE * MINIMAP + i;
            screen_y = y * TILE * MINIMAP + j;
            mlx_put_pixel(cub->mlx.img_ptr, screen_x, screen_y, color);
            i++;
        }
        j++;
    }
}

void        draw_minimap(t_cub *cub)
{
    int x;
    int y;
    int color;
    
    x = 0;
    y = 0;
    while(y < cub->map.height && y < SCREEN_HEIGHT / (TILE * MINIMAP))
    {
        x = 0;
        while (x < cub->map.width && SCREEN_WIDTH / (TILE * MINIMAP))
        {
            if(cub->map.map[y][x] == '1')
                color = 0x808080;
            else
                color = 0x000000;
            draw_tile(cub, x, y, color);
            x++;
        }
        y++;
    }
}

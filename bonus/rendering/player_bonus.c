#include "../cub3d_bonus.h"

void     draw_player(t_cub *cub)
{
    int i = -4;
    int j = -4;
    int screen_x = cub->ply.ply_x * TILE * MINIMAP;
    int screen_y = cub->ply.ply_y * TILE * MINIMAP;

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

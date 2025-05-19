#include "../cub3d_bonus.h"

void    draw_rays(t_cub *cub)
{
    int i;
    
    i = 0;
    cub->dda.start_x = cub->ply.ply_x * (TILE*MINIMAP);
    cub->dda.start_y = cub->ply.ply_y * (TILE*MINIMAP);
    while(i < SCREEN_WIDTH)
    {
        cub->dda.end_x = cub->ray[i].wall_hit_x;
        cub->dda.end_y = cub->ray[i].wall_hit_y;
        DDA(cub, cub->dda);
        i++;
    }
}

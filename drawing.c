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
            while(j < TILE*MINIMAP)
            {
                i = 0;
                while(i < TILE*MINIMAP)
                {
                    screen_x = x * TILE*MINIMAP + i;
                    screen_y = y * TILE*MINIMAP + j;
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
    i = 0;

    while(i < SCREEN_WIDTH)
    {
        DDA(cub, cub->ply.pos_x, cub->ply.pos_y, cub->ray[i].end_x, cub->ray[i].end_y);
        i++;
    }
}

void     draw_player(t_cub *cub)
{
    int i = -4;
    int j = -4;
    int screen_x = cub->ply.pos_x;
    int screen_y = cub->ply.pos_y;

    while(j < 4)
    {
        i = -4;
        while(i < 4)
        {
            if(i * i + j * j <= 16)
                mlx_put_pixel(cub->mlx.img_ptr ,screen_x + j, screen_y + i, 0x808080);
            i++;
        }
        j++;
    }
}

void    draw_ceiling(t_cub cub, int top, int x)
{
    int y = 0;

    while(y < top)
    {
        mlx_put_pixel(cub.mlx.img_ptr, x, y, 0x89CFF3FF);
        y++;
    }

}

void    draw_floor(t_cub cub, int bottom, int x)
{
    int y = bottom;

    while(y < SCREEN_HEIGHT)
    {
        mlx_put_pixel(cub.mlx.img_ptr, x, y, 0xB99470FF);
        y++;
    }
}

void draw_wall(t_cub *cub, int x)
{
    int wall_top;
    int wall_bottom;
    float wall_height;
    float distance_to_projection_plane;

    // printf("%f\n", cub->ray[x].distance);
    cub->ray[x].distance *= cos(degree_to_radian(normalize_angle(cub->ray[x].ray_angle - cub->ply.angle))); // fix the fisheye
    distance_to_projection_plane = (SCREEN_WIDTH / 2) / tan(degree_to_radian(FOV) / 2);
    wall_height = (TILE*MINIMAP / cub->ray[x].distance) * distance_to_projection_plane;
    // printf("distance %f x %d angle %f height %f\n", cub->ray[x].distance, x, cub->ray[x].ray_angle, wall_height);
    wall_top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    wall_bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);
    if (wall_top < 0) wall_top = 0;
    if(wall_bottom > SCREEN_HEIGHT) wall_bottom = SCREEN_HEIGHT;
    int y = wall_top;
    while (y < wall_bottom)
    {
        mlx_put_pixel(cub->mlx.img_ptr, x, y, 0xFFFFFF);
        y++;
    }
    draw_ceiling(*cub, wall_top, x);
    draw_floor(*cub, wall_bottom, x);
}


#include "../cub3d.h"

void    draw_minimap(t_cub *cub)
{
    int color;
    int y = 0;
    int x = 0;
    int i = 0;
    int j = 0;
    int screen_y;
    int screen_x;
    // printf("height: %d | width: %d\n", cub->map.height, cub->map.width);
    // for(int i = 0; i < cub->map.height; i++)
    //     printf("%s\n", cub->map.map[i]);
    while(y < cub->map.height)
    {
        x = 0;
        while (x < cub->map.width)
        {
            // printf("y: %d | x: %d\n", y, x);
            if(cub->map.map[y][x] == 1)
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
                    if (screen_x >= 0 && screen_x < SCREEN_WIDTH && screen_y >= 0 && screen_y < SCREEN_HEIGHT)
                        mlx_put_pixel(cub->mlx.img_ptr, screen_x, screen_y, color);
                    else
                        printf("map out of screen bounds!\n");
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
        DDA(cub, cub->ply.pos_x * (TILE*MINIMAP), cub->ply.pos_y * (TILE*MINIMAP), cub->ray[i].end_x, cub->ray[i].end_y);
        i++;
    }
}

void     draw_player(t_cub *cub)
{
    // printf("px: %f | py: %f\n", cub->ply.pos_x/(TILE*MINIMAP), cub->ply.pos_y/(TILE*MINIMAP));
    // exit(0);
    int i = -4;
    int j = -4;
    int screen_x = cub->ply.pos_x * TILE * MINIMAP;
    int screen_y = cub->ply.pos_y * TILE * MINIMAP;

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

void draw_wall(t_cub *cub, int x, int check)
{
    int wall_top;
    int wall_bottom;
    float wall_height;
    float distance_to_projection_plane;
    uint32_t color;

    // printf("%f\n", cub->ray[x].distance);
    if(check == 1)
        color = 0xF5F5F5FF;
    else 
        color = 0xB5B5B5FF;
    cub->ray[x].distance *= cos(degree_to_radian(normalize_angle(cub->ray[x].ray_angle - cub->ply.ply_angle))); // fix the fisheye
    distance_to_projection_plane = (SCREEN_WIDTH / 2) / tan(degree_to_radian(FOV) / 2);
    // wall_height = (TILE*MINIMAP / cub->ray[x].distance) * distance_to_projection_plane;
    wall_height = (TILE / cub->ray[x].distance) * distance_to_projection_plane;
    // printf("distance %f x %d angle %f height %f\n", cub->ray[x].distance, x, cub->ray[x].ray_angle, wall_height);
    wall_top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    wall_bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);
    if (wall_top < 0) wall_top = 0;
    if(wall_bottom > SCREEN_HEIGHT) wall_bottom = SCREEN_HEIGHT;
    int y = wall_top;
    while (y < wall_bottom)
    {
        // 0xFFFFFF
        mlx_put_pixel(cub->mlx.img_ptr, x, y, color);
        y++;
    }
    draw_ceiling(*cub, wall_top, x);
    draw_floor(*cub, wall_bottom, x);
}

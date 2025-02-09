#include "cub3d.h"

int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void    draw_map(void *mlx_ptr, void *win_ptr)
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
            if(worldMap[y][x] == 1)
                color = 0x808080;
            else
                color = 0x000000;
            j = 0;
            while(j < TILE_SIZE)
            {
                i = 0;
                while(i < TILE_SIZE)
                {
                    screen_x = x * TILE_SIZE + i;
                    screen_y = y * TILE_SIZE + j;
                    mlx_pixel_put(mlx_ptr, win_ptr, screen_x, screen_y, color);
                    i++;
                }
                j++;
            }
            x++;
        }
        y++;
    }

}

void    draw_player(void *mlx_ptr, void *win_ptr, t_ply player)
{
    int i = -4;
    int j = -4;
    int screen_x = player.pos_x * TILE_SIZE;
    int screen_y = player.pos_y * TILE_SIZE;

    while(j < 4)
    {
        i = -4;
        while(i < 4)
        {
            if(i * i + j * j <= 16)
                mlx_pixel_put(mlx_ptr, win_ptr, screen_x + i, screen_y + j, 0xFF0000);
            i++;
        }
        j++;
    }
}

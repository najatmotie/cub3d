#include "cub3d.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

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

void    draw_player(void *mlx_ptr, void *win_ptr, t_ply *player)
{
    int i = -4;
    int j = -4;
    int screen_x = player->p_x * TILE_SIZE;
    int screen_y = player->p_y * TILE_SIZE;

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

int main(int ac, char **av)
{
    // int width;
    // int height;
    t_cub cub;

    (void)av;
    if(ac == 2)
    {
        t_ply player = {1.5, 1.5, -1, 0};
        cub.mlx.mlx_ptr = mlx_init();
        // cub.mlx.mlx = mlx_init(cub.mlx.mlx, width * TILE_SIZE, height * TILE_SIZE, "cub3D", 0);
        // get_map_size(av[1], &width, &height);
        // cub.map = fill_map(av[1], width, height, &cub);
        cub.mlx.win_ptr = mlx_new_window(cub.mlx.mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "cub3D");
        // mlx_key_hook(cub.mlx.win_ptr, key_hook, &cub);
        mlx_hook(cub.mlx.win_ptr, 2, 0, key_hook, &cub);
        // mlx_hook(cub.mlx.win_ptr, 3, 0, key_hook, &cub);
        mlx_hook(cub.mlx.win_ptr, 17, 0, close_window, &cub);
        // mlx_pixel_put(cub.mlx.mlx_ptr, cub.mlx.win_ptr, 400, 300, 0xFF0000);
        draw_map(cub.mlx.mlx_ptr, cub.mlx.win_ptr);
        draw_player(cub.mlx.mlx_ptr, cub.mlx.win_ptr, &player);
        mlx_loop(cub.mlx.mlx_ptr);
        
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
} 

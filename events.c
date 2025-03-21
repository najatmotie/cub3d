#include "cub3d.h"

int inside_bounds(float x, float y)
{
    if(x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
        return 1;
    return 0;
}

int normalize_angle(int angle)
{
    if(angle > 360)
        angle -= 360;
    if(angle < 0)
        angle += 360;
    return(angle);
}

void key_hook(void *param)
{

    t_cub *cub = (t_cub*)param;
    double move_speed = 0.5;
    double rotation_speed = 1;
    float radian = cub->ply.angle * M_PI / 180.0;
    float new_x = 0;
    float new_y = 0;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
    {
        mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
		mlx_close_window(cub->mlx.mlx_ptr);
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
    {
        new_x = (cub->ply.pos_x + cos(radian) * move_speed) / 50;
        new_y = (cub->ply.pos_y - sin(radian) * move_speed) / 50;

        if(inside_bounds(new_x, new_y) && !Map[(int)new_y][(int)new_x])
        {
            cub->ply.pos_x += cos(radian) * move_speed;
            cub->ply.pos_y -= sin(radian) * move_speed;
        }
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
	{
        new_x = (cub->ply.pos_x - cos(radian) * move_speed) / 50;
        new_y = (cub->ply.pos_y + sin(radian) * move_speed) / 50;
        // printf("%d %d\n", inside_bounds(new_x, new_y), Map[(int)new_y][(int)new_x]);
        // printf("new_x %f new_y %f ", new_x, new_y);
        if(inside_bounds(new_x, new_y) && !Map[(int)new_y][(int)new_x])
        {
            cub->ply.pos_x -= cos(radian) * move_speed;
            cub->ply.pos_y += sin(radian) * move_speed;
        }
    }	
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
	{
        new_x = (cub->ply.pos_x + cos(radian + M_PI / 2) * move_speed) / 50;
        new_y = (cub->ply.pos_y - sin(radian + M_PI / 2) * move_speed) / 50;
        if(inside_bounds(new_x, new_y) && !Map[(int)new_y][(int)new_x])
        {
            // printf("A %f\n", radian + M_PI / 2);
            cub->ply.pos_x += cos(radian + M_PI / 2) * move_speed;
            cub->ply.pos_y -= sin(radian + M_PI / 2) * move_speed;
        }
    }	
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
	{
        new_x = (cub->ply.pos_x - cos(radian + M_PI / 2) * move_speed) / 50;
        new_y = (cub->ply.pos_y + sin(radian + M_PI / 2) * move_speed) / 50;
        if(inside_bounds(new_x, new_y) && !Map[(int)new_y][(int)new_x])
        {
            cub->ply.pos_x -= cos(radian + M_PI / 2) * move_speed;
            cub->ply.pos_y += sin(radian + M_PI / 2) * move_speed;
        }
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
        cub->ply.angle += rotation_speed;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
        cub->ply.angle -= rotation_speed;
    cub->ply.angle = normalize_angle(cub->ply.angle);
    // printf("angle %f\n", cub->ply.angle);

    mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
    cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, MAP_WIDTH * TILE, MAP_HEIGHT * TILE);
    if(!cub->mlx.img_ptr)
    {
        printf("Error: Image pointer is NULL\n");
        exit(1);
    }
    mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
    draw_minimap(cub);
    draw_player(cub);
    cast_all_rays(cub);
}

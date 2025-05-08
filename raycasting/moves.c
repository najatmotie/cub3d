#include "../cub3d.h"

void key_hook(void *param)
{
    float new_x = 0;
    float new_y = 0;
    t_cub *cub = (t_cub*)param;

    // x:26.5 | y:11.5
    // printf("before: %f %f\n", cub->ply.pos_x,cub->ply.pos_y);

    // printf("x cos(0):    %f  y sin(0): %f\n", cos(degree_to_radian(0)), sin(degree_to_radian(0)));
    // printf("x cos(90):   %f  y sin(90): %f\n", cos(degree_to_radian(90)), sin(degree_to_radian(90)));
    // printf("x cos(180):  %f  y sin(180): %f\n", cos(degree_to_radian(180)), sin(degree_to_radian(180)));
    // printf("x cos(270):  %f  y sin(270): %f\n", cos(degree_to_radian(270)), sin(degree_to_radian(270)));
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
    {
        mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
		mlx_close_window(cub->mlx.mlx_ptr);
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
    {
        new_x = cub->ply.pos_x + cos(degree_to_radian(cub->ply.ply_angle)) * MOVE_SPEED;
        new_y = cub->ply.pos_y - sin(degree_to_radian(cub->ply.ply_angle)) * MOVE_SPEED;
        // printf("%c\n",cub->map.map[(int)new_y][(int)new_x]);
        if(inside_bounds(*cub, new_x, new_y) && cub->map.map[(int)new_y][(int)new_x] != '1')
        {
            // printf("after: %f %f\n", new_x,new_y);
            // exit(0);
            cub->ply.pos_x = new_x;
            cub->ply.pos_y = new_y;
        }
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
	{
        new_x = cub->ply.pos_x - cos(degree_to_radian(cub->ply.ply_angle)) * MOVE_SPEED;
        new_y = cub->ply.pos_y + sin(degree_to_radian(cub->ply.ply_angle)) * MOVE_SPEED;
        // printf("%d %d\n", inside_bounds(*cub, new_x, new_y), cub->map.map[(int)new_y][(int)new_x]);
        // printf("new_x %f new_y %f ", new_x, new_y);
        if(inside_bounds(*cub, new_x, new_y) && cub->map.map[(int)new_y][(int)new_x] != '1')
        {
            cub->ply.pos_x = new_x;
            cub->ply.pos_y = new_y;
        }
    }	
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
	{
        new_x = cub->ply.pos_x + cos(degree_to_radian(cub->ply.ply_angle) + M_PI / 2) * MOVE_SPEED;
        new_y = cub->ply.pos_y - sin(degree_to_radian(cub->ply.ply_angle) + M_PI / 2) * MOVE_SPEED;
        if(inside_bounds(*cub, new_x, new_y) && cub->map.map[(int)new_y][(int)new_x] != '1')
        {
            // printf("A %f\n", degree_to_radian(cub->ply.ply_angle) + M_PI / 2);
            cub->ply.pos_x = new_x;
            cub->ply.pos_y = new_y;
        }
    }	
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
	{
        new_x = cub->ply.pos_x - cos(degree_to_radian(cub->ply.ply_angle) + M_PI / 2) * MOVE_SPEED;
        new_y = cub->ply.pos_y + sin(degree_to_radian(cub->ply.ply_angle) + M_PI / 2) * MOVE_SPEED;
        if(inside_bounds(*cub, new_x, new_y) && cub->map.map[(int)new_y][(int)new_x] != '1')
        {
            cub->ply.pos_x = new_x;
            cub->ply.pos_y = new_y;
        }
        // printf("ppx: %f | ppy: %f\n", cub->ply.pos_x/(TILE*MINIMAP), cub->ply.pos_y/(TILE*MINIMAP));
    }
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
        cub->ply.ply_angle += ROTATION_SPEED;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
        cub->ply.ply_angle -= ROTATION_SPEED;
    cub->ply.ply_angle = normalize_angle(cub->ply.ply_angle);
    // printf(" after: %f %f\n", cub->ply.pos_x,cub->ply.pos_y);
    if(cub->mlx.img_ptr)
        mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
    cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
    cast_all_rays(cub);
    draw_minimap(cub);
    draw_player(cub);
}

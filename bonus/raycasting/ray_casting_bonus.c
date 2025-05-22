#include "../cub3d_bonus.h"

t_ray cast_ray(t_cub *cub, int x)
{
    t_ray ray;
    t_ray shortest;
    t_ray vertical;
    t_ray horisontal;
    
    vertical = get_vertical(cub, cub->ray[x].ray_angle);
    horisontal = get_horisontal(cub, cub->ray[x].ray_angle);
    shortest = shortest_distance(horisontal, vertical, cub->ray[x].ray_angle);
    ray.wall_hit_x = shortest.wall_hit_x;
    ray.wall_hit_y = shortest.wall_hit_y;
    ray.wall_side = shortest.wall_side;
    ray.distance_to_wall = shortest.distance_to_wall;
    return ray;
}

void    cast_rays(t_cub *cub)
{
    int x;
    float fov;
    int num_rays;
    float ray_angle_increment;

    x = 0;
    fov = FOV;
    num_rays = SCREEN_WIDTH;
    ray_angle_increment = fov / num_rays;
    cub->dda.start_x = cub->ply.ply_x * (TILE*MINIMAP);
    cub->dda.start_y = cub->ply.ply_y * (TILE*MINIMAP);
    while(x < num_rays)
    {
        cub->ray[x].ray_angle = (cub->ply.ply_angle + (fov / 2)) - (x * ray_angle_increment);
        cub->ray[x].ray_angle = normalize_angle(cub->ray[x].ray_angle);
        cub->ray[x] = cast_ray(cub, x);
        // cub->dda.end_x = cub->ray[x].wall_hit_x;
        // cub->dda.end_y = cub->ray[x].wall_hit_y;
        // DDA(cub, cub->dda);
        draw_3d(cub, x);
        x++;
    }
}

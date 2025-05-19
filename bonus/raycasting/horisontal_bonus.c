#include "../cub3d_bonus.h"

t_ray    get_first_tile_ray_h(t_cub *cub, float ray_angle)
{
    t_ray ray;
    int value;
    float opposite;
    float adjacent;

    ray.wall_hit_x = cub->ply.ply_x * (TILE * MINIMAP);
    ray.wall_hit_y = cub->ply.ply_y * (TILE * MINIMAP);
    if(ray_angle >= 0 && ray_angle <= 180)
    {
        value = ray.wall_hit_y / (TILE * MINIMAP);
        opposite = ray.wall_hit_y - value * (TILE * MINIMAP);
        ray.wall_hit_y -= opposite;
    }
    else
    {
        value = ray.wall_hit_y / (TILE * MINIMAP);
        opposite = (value * (TILE * MINIMAP) + (TILE * MINIMAP)) - ray.wall_hit_y;
        ray.wall_hit_y += opposite;
    }
    adjacent = opposite / fabs(tan(degree_to_radian(ray_angle)));
    if(ray_angle >= 90 && ray_angle <= 270)
        ray.wall_hit_x -= adjacent;
    else
        ray.wall_hit_x += adjacent;
    return ray;
}

// bool check_wall()
// {
// }

t_ray    complete_ray_until_hit_wall_h(t_cub *cub, t_ray ray, float ray_angle)
{
    int grid_x;
    int grid_y;
    float opposite;
    float adjacent;

    opposite = (TILE * MINIMAP);
    adjacent = opposite / fabs(tan(degree_to_radian(ray_angle)));
    while(inside_bounds(*cub, ray.wall_hit_x/(TILE * MINIMAP), ray.wall_hit_y/(TILE * MINIMAP)))
    {
        grid_x = (int)ray.wall_hit_x/(TILE * MINIMAP);
        grid_y = (int)ray.wall_hit_y/(TILE * MINIMAP);

        if (ray_angle < 180)
            grid_y = (int)(ray.wall_hit_y - 1)/(TILE * MINIMAP);
        if (cub->map.map[grid_y][grid_x] == '1')
            break ;
        // if (cub->map.map[grid_y][grid_x] == '1' || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y - 1][grid_x] == '1' && cub->map.map[grid_y][grid_x - 1] == '1') 
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y - 1][grid_x] == '1' && cub->map.map[grid_y][grid_x + 1] == '1')
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y + 1][grid_x] == '1' && cub->map.map[grid_y][grid_x + 1] == '1')
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y + 1][grid_x] == '1' && cub->map.map[grid_y][grid_x - 1] == '1'))
        //     break ;
        if(ray_angle >= 0 && ray_angle <= 180)
            ray.wall_hit_y -= opposite;
        else
            ray.wall_hit_y += opposite;
        if(ray_angle >= 90 && ray_angle <= 270)
            ray.wall_hit_x -= adjacent;
        else
            ray.wall_hit_x += adjacent;
    }
    return ray;
}

t_ray get_horisontal(t_cub *cub, float ray_angle)
{
    t_ray ray;

    ray = get_first_tile_ray_h(cub, ray_angle);
    ray = complete_ray_until_hit_wall_h(cub, ray, ray_angle);
    ray.distance_to_wall = calculate_distance(cub->ply.ply_x * (TILE * MINIMAP), cub->ply.ply_y * (TILE * MINIMAP), ray.wall_hit_x, ray.wall_hit_y);
    return ray;
}

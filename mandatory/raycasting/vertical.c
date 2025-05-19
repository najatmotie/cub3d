#include "../cub3d.h"

t_ray    get_first_tile_ray_v(t_cub *cub, float ray_angle)
{
    t_ray ray;
    int value;
    float opposite;
    float adjacent;

    ray.wall_hit_x = cub->ply.ply_x * TILE;
    ray.wall_hit_y = cub->ply.ply_y * TILE;
    if(ray_angle >= 90 && ray_angle <= 270)
    {
        value = ray.wall_hit_x / TILE;
        adjacent = ray.wall_hit_x - value * TILE;
        ray.wall_hit_x -= adjacent;
    }
    else
    {
        value = ray.wall_hit_x / TILE;
        adjacent = (value * TILE + TILE) - ray.wall_hit_x;
        ray.wall_hit_x += adjacent;
    }
    opposite = adjacent * fabs(tan(degree_to_radian(ray_angle)));
    if(ray_angle >= 0 && ray_angle <= 180)
        ray.wall_hit_y -= opposite;
    else
        ray.wall_hit_y += opposite;
    return ray;
}

// bool check_wall()
// {
// }

t_ray    complete_ray_until_hit_wall_v(t_cub *cub, t_ray ray, float ray_angle)
{
    int grid_x;
    int grid_y;
    float opposite;
    float adjacent;

    adjacent = TILE;
    opposite = adjacent * fabs(tan(degree_to_radian(ray_angle)));
    while(inside_bounds(*cub, ray.wall_hit_x/TILE, ray.wall_hit_y/TILE))
    {
        grid_x = (int)ray.wall_hit_x/TILE;
        grid_y = (int)ray.wall_hit_y/TILE;

        if (ray_angle > 90 && ray_angle < 270)
            grid_x = (int)(ray.wall_hit_x - 1)/TILE;
        if (cub->map.map[grid_y][grid_x] == '1')
            break ;
        // if (cub->map.map[grid_y][grid_x] == '1' || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y - 1][grid_x] == '1' && cub->map.map[grid_y][grid_x - 1] == '1') 
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y - 1][grid_x] == '1' && cub->map.map[grid_y][grid_x + 1] == '1')
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y + 1][grid_x] == '1' && cub->map.map[grid_y][grid_x + 1] == '1')
        //     || (cub->map.map[grid_y][grid_x] == '0' && cub->map.map[grid_y + 1][grid_x] == '1' && cub->map.map[grid_y][grid_x - 1] == '1'))
        //     break ;
        if(ray_angle >= 90 && ray_angle <= 270)
            ray.wall_hit_x -= adjacent;
        else
            ray.wall_hit_x += adjacent;
        if(ray_angle >= 0 && ray_angle <= 180)
            ray.wall_hit_y -= opposite;
        else
            ray.wall_hit_y += opposite;
    }
    return ray;
}

t_ray get_vertical(t_cub *cub, float ray_angle)
{
    t_ray ray;

    ray = get_first_tile_ray_v(cub, ray_angle);
    ray = complete_ray_until_hit_wall_v(cub, ray, ray_angle);
    ray.distance_to_wall = calculate_distance(cub->ply.ply_x * TILE, cub->ply.ply_y * TILE, ray.wall_hit_x, ray.wall_hit_y);
    return ray;
}

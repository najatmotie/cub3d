#include "../cub3d.h"

t_ray shortest_distance(t_ray a, t_ray b, int *color)
{
    if(a.distance <= b.distance) 
    {
        *color = 1;
        return a;
    }
    *color = 0;
    return b;
}

t_ray get_horisontal(t_cub *cub, float ray_angle)
{
    int value;
    double opposite;
    double adjacent;
    float x = cub->ply.pos_x * (TILE*MINIMAP);
    float y = cub->ply.pos_y * (TILE*MINIMAP);

    t_ray point;
    float radian = ray_angle * M_PI / 180.0;
    if(ray_angle >= 0 && ray_angle <= 180)
    {
        value = cub->ply.pos_y / (TILE*MINIMAP);
        opposite = cub->ply.pos_y - value * (TILE*MINIMAP);
        y -= opposite;
    }
    else
    {
        value = cub->ply.pos_y / (TILE*MINIMAP);
        opposite = (value * (TILE*MINIMAP) + (TILE*MINIMAP)) - cub->ply.pos_y;
        y += opposite;
    }
    adjacent = opposite / fabs(tan(radian));
    if(ray_angle >= 90 && ray_angle <= 270)
        x -= adjacent;
    else
        x += adjacent;
    opposite = (TILE*MINIMAP);
    adjacent = opposite / fabs(tan(radian));
    while(inside_bounds(cub, x/(TILE*MINIMAP), y/(TILE*MINIMAP)))
    {
        int grid_x = (int)x/(TILE*MINIMAP);
        int grid_y = (int)y/(TILE*MINIMAP);

        if (ray_angle < 180)
            grid_y = (int)(y - 1)/(TILE*MINIMAP);
        if (cub->map.map[grid_y][grid_x] == 1)
            break;
        if(ray_angle >= 0 && ray_angle <= 180)
            y -= opposite;
        else
            y += opposite;
       if(ray_angle >= 90 && ray_angle <= 270)
            x -= adjacent;
        else
            x += adjacent;
    }
    point.end_x = x;
    point.end_y = y;
    point.distance = calculate_distance(cub->ply.pos_x, cub->ply.pos_y, x, y);
    return point;
}

t_ray get_vertical(t_cub *cub, float ray_angle)
{
    int value;
    float opposite;
    float adjacent;
    float x = cub->ply.pos_x * (TILE*MINIMAP);
    float y = cub->ply.pos_y * (TILE*MINIMAP);
    t_ray point;
    float radian = ray_angle * M_PI / 180.0;

    if(ray_angle >= 90 && ray_angle <= 270)
    {
        value = cub->ply.pos_x / (TILE*MINIMAP);
        adjacent = cub->ply.pos_x - value * (TILE*MINIMAP);
        x -= adjacent;
    }
    else
    {
        value = cub->ply.pos_x / (TILE*MINIMAP);
        adjacent = (value * (TILE*MINIMAP) + (TILE*MINIMAP)) - cub->ply.pos_x;
        x += adjacent;
    }
    opposite = adjacent * fabs(tan(radian));
    if(ray_angle >= 0 && ray_angle <= 180)
        y -= opposite;
    else
        y += opposite;
    adjacent = (TILE*MINIMAP);
    opposite = adjacent * fabs(tan(radian));
    while(inside_bounds(cub, x/(TILE*MINIMAP), y/(TILE*MINIMAP)))
    {
        int grid_x = (int)x/(TILE*MINIMAP);
        int grid_y = (int)y/(TILE*MINIMAP);

        if (ray_angle > 90 && ray_angle < 270)
            grid_x = (int)(x - 1)/(TILE*MINIMAP);
        if (cub->map.map[grid_y][grid_x] == 1)
            break;
        if(ray_angle >= 90 && ray_angle <= 270)
            x -= adjacent;
        else
            x += adjacent;
        if(ray_angle >= 0 && ray_angle <= 180)
            y -= opposite;
        else
            y += opposite;
    }
    point.end_x = x;
    point.end_y = y;
    point.distance = calculate_distance(cub->ply.pos_x, cub->ply.pos_y, x, y);
    return point;
}

t_ray cast_ray(t_cub *cub, int *color)
{
    t_ray ray;
    t_ray horisontal = get_horisontal(cub, cub->ray->ray_angle);
    t_ray vertical = get_vertical(cub, cub->ray->ray_angle);
    t_ray shortest = shortest_distance(horisontal, vertical, color);

    ray.end_x = shortest.end_x;
    ray.end_y = shortest.end_y;
    ray.distance = shortest.distance;
    // printf("x %f y %f d %f\n", ray.end_x,ray.end_y,ray.distance);
    return ray;
}

void    cast_all_rays(t_cub *cub)
{
    int i = 0;
    int color;
    float ray_angle;
    float fov = FOV;
    int num_rays = SCREEN_WIDTH;
    float ray_angle_increment = fov / num_rays;
    while(i < num_rays)
    {
        ray_angle = cub->ply.angle - (fov / 2) + (i * ray_angle_increment);
        ray_angle = normalize_angle(ray_angle);
        cub->ray[i].ray_angle = ray_angle;
        cub->ray[i] = cast_ray(cub, &color);
        draw_wall(cub, i, color);
        i++;
    }
}

#include "cub3d.h"

int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 

int calculate_distance(x1, y1, x2, y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void DDA(t_cub *cub, float X0, float Y0, float X1, float Y1) 
{
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float)steps; 
    float Yinc = dy / (float)steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) { 
        // putpixel(round(X), round(Y), 0xFF0000); // put pixel at (X,Y)
        if(!inside_bounds(X1/TILE, Y1/TILE))
            return ;
        mlx_put_pixel(cub->mlx.img_ptr, round(X),  round(Y), 0xFFFFFF);
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step 
    } 
}

t_ray get_horisontal(t_cub *cub, float ray_angle)
{
    int value;
    double opposite;
    double adjacent;
    float x = cub->ply.pos_x;
    float y = cub->ply.pos_y;

    t_ray point;
    float radian = ray_angle * M_PI / 180.0;
    if(ray_angle >= 0 && ray_angle <= 180)
    {
        value = cub->ply.pos_y / TILE;
        opposite = cub->ply.pos_y - value * TILE;
        y -= opposite;
    }
    else
    {
        value = cub->ply.pos_y / TILE;
        opposite = (value * TILE + TILE) - cub->ply.pos_y;
        y += opposite;
    }
    adjacent = opposite / fabs(tan(radian));
    if(ray_angle >= 90 && ray_angle <= 270)
        x -= adjacent;
    else
        x += adjacent;
    opposite = TILE;
    adjacent = opposite / fabs(tan(radian));
    while(inside_bounds(x/TILE, y/TILE))
    {
        int grid_x = (int)x/TILE;
        int grid_y = (int)y/TILE;

        if (ray_angle < 180)
            grid_y = (int)(y - 1)/TILE;
        if (Map[grid_y][grid_x] == 1)
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
    float x = cub->ply.pos_x;
    float y = cub->ply.pos_y;
    t_ray point;
    float radian = ray_angle * M_PI / 180.0;

    if(ray_angle >= 90 && ray_angle <= 270)
    {
        value = cub->ply.pos_x / TILE;
        adjacent = cub->ply.pos_x - value * TILE;
        x -= adjacent;
    }
    else
    {
        value = cub->ply.pos_x / TILE;
        adjacent = (value * TILE + TILE) - cub->ply.pos_x;
        x += adjacent;
    }
    opposite = adjacent * fabs(tan(radian));
    if(ray_angle >= 0 && ray_angle <= 180)
        y -= opposite;
    else
        y += opposite;
    adjacent = TILE;
    opposite = adjacent * fabs(tan(radian));
    while(inside_bounds(x/TILE, y/TILE))
    {
        int grid_x = (int)x/TILE;
        int grid_y = (int)y/TILE;

        if (ray_angle > 90 && ray_angle < 270)
            grid_x = (int)(x - 1)/TILE;
        if (Map[grid_y][grid_x] == 1)
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

t_ray shortest_distance(t_ray a, t_ray b)
{
    if(a.distance < b.distance) return a;
    return b;
}

t_ray cast_ray(t_cub *cub, float ray_angle)
{
    t_ray ray;
    t_ray horisontal = get_horisontal(cub, ray_angle);
    t_ray vertical = get_vertical(cub, ray_angle);
    t_ray shortest = shortest_distance(horisontal, vertical);

    ray.end_x = shortest.end_x;
    ray.end_y = shortest.end_y;
    ray.distance = shortest.distance;
       
    return ray;
}

void    cast_all_rays(t_cub *cub)
{
    int i = 0;
    float ray_angle;
    // float distance;
    t_ray ray;
    float fov = FOV;
    int num_rays = MAP_WIDTH * TILE;
    // printf("%d\n", num_rays);
    float ray_angle_increment = fov / num_rays;
    // printf("%f\n", ray_angle_increment);
    while(i < num_rays)
    {
        ray_angle = cub->ply.angle - (fov / 2) + (i * ray_angle_increment);
        // printf("%d %f\n",i, ray_angle);
        ray_angle = normalize_angle(ray_angle);
        ray = cast_ray(cub, ray_angle);
        // printf("x %f y %f\n", ray.end_x, ray.end_y);
        DDA(cub, cub->ply.pos_x, cub->ply.pos_y, ray.end_x, ray.end_y);
        i++;
    }
}

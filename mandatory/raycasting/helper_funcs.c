#include "../cub3d.h"

float degree_to_radian(float angle)
{
    return(angle * M_PI / 180.0);
}

float normalize_angle(float angle)
{
    if(angle > 360)
        angle -= 360;
    if(angle < 0)
        angle += 360;
    return(angle);
}

int inside_bounds(t_cub cub, float x, float y)
{
    if(x >= 0 && x < cub.map.width && y >= 0 && y < cub.map.height)
        return 1;
    return 0;
}

int screen_bounds(float x, float y)
{
    if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        return 1;
    return 0;
}

float calculate_distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

t_ray shortest_distance(t_ray horisontal, t_ray vertical, float ray_angle)
{
    if(horisontal.distance_to_wall <= vertical.distance_to_wall)
    {
        if(sin(degree_to_radian(normalize_angle(ray_angle))) > 0)
            horisontal.wall_side = 'N';
        else
            horisontal.wall_side = 'S';
        return horisontal;
    }
    if(cos(degree_to_radian(normalize_angle(ray_angle))) > 0)
        vertical.wall_side = 'E';
    else
        vertical.wall_side = 'W';
    return vertical;
}

bool check_wall(t_cub cub, int x, int y, float angle)
{
    if (cub.map.map[y][x] == '1' 
        || (cub.map.map[y][x] == '0' && cub.map.map[y - 1][x] == '1' && cub.map.map[y][x - 1] == '1' && (int)angle  == 315)
        || (cub.map.map[y][x] == '0' && cub.map.map[y - 1][x] == '1' && cub.map.map[y][x + 1] == '1' && (int)angle  == 225)
        || (cub.map.map[y][x] == '0' && cub.map.map[y + 1][x] == '1' && cub.map.map[y][x + 1] == '1' && (int)angle  == 135)
        || (cub.map.map[y][x] == '0' && cub.map.map[y + 1][x] == '1' && cub.map.map[y][x - 1] == '1' && (int)angle  == 45))
        return true;
    return false;
}

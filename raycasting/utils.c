#include "../cub3d.h"
void    ft_free(char **map)
{
    int i = 0;

    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    map = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 

float calculate_distance(float x1, float y1, float x2, float y2)
{
    // return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);

}

float degree_to_radian(float angle)
{
    return(angle * M_PI / 180.0);
}

int inside_bounds(t_cub *cub, float x, float y)
{
    if(x >= 0 && x < cub->map.width && y >= 0 && y < cub->map.height)
        return 1;
    return 0;
}

float normalize_angle(float angle)
{
    if(angle > 360)
        angle -= 360;
    if(angle < 0)
        angle += 360;
    return(angle);
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
        if(!inside_bounds(cub, X1/(TILE*MINIMAP), Y1/(TILE*MINIMAP)))
            return ;
        mlx_put_pixel(cub->mlx.img_ptr, round(X),  round(Y), 0xFFFFFF);
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step 
    } 
}

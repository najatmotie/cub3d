#include "../cub3d.h"

void DDA(t_cub *cub, t_dda dda) 
{
    int i;
    float x;
    float y;
    float x_increment;
    float y_increment;

    if(!inside_bounds(*cub, dda.end_x/TILE, dda.end_y/TILE))
        return ;
    dda.distance_x = dda.end_x - dda.start_x; 
    dda.distance_y = dda.end_y - dda.start_y; 
    if(abs(dda.distance_x) > abs(dda.distance_y))
        dda.pixels_steps = abs(dda.distance_x);
    else 
        dda.pixels_steps = abs(dda.distance_y);
    
    x_increment = dda.distance_x / (float)dda.pixels_steps; 
    y_increment = dda.distance_y / (float)dda.pixels_steps; 
    x = dda.start_x; 
    y = dda.start_y; 
    i = 0;
    while(i <= dda.pixels_steps) 
    { 
        mlx_put_pixel(cub->mlx.img_ptr, round(x),  round(y), 0xFFFFFF);
        x += x_increment;  
        y += y_increment;
        i++;
    } 
}

// void DDA(t_cub *cub, float X0, float Y0, float X1, float Y1) 
// {
//     // calculate dx & dy 
//     int dx = X1 - X0; 
//     int dy = Y1 - Y0; 
//     // calculate steps required for generating pixels 
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
//     // calculate increment in x & y for each steps 
//     float Xinc = dx / (float)steps; 
//     float Yinc = dy / (float)steps; 
  
//     // Put pixel for each step 
//     float X = X0; 
//     float Y = Y0; 
//     for (int i = 0; i <= steps; i++) { 
//         // putpixel(round(X), round(Y), 0xFF0000); // put pixel at (X,Y)
//         if(!inside_bounds(*cub, X1/(TILE), Y1/(TILE)))
//             return ;
//             // printf("jjgj\n");
//         mlx_put_pixel(cub->mlx.img_ptr, round(X),  round(Y), 0xFFFFFF);
//         X += Xinc; // increment in x at each step 
//         Y += Yinc; // increment in y at each step 
//     } 
// }

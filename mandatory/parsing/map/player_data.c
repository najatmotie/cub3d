#include "../../cub3d.h"

void	north_info(t_cub *cub, int i, int j)
{
	cub->elements.N++;
	cub->ply.ply_x = j + 0.5;
    cub->ply.ply_y = i + 0.5;
    cub->ply.ply_angle = 90;
}

void	south_info(t_cub *cub, int i, int j)
{
	cub->elements.S++;
	cub->ply.ply_x = j;
    cub->ply.ply_y = i;
    cub->ply.ply_angle = 270;
}

void	west_info(t_cub *cub, int i, int j)
{
	cub->elements.W++;
	cub->ply.ply_x = j;
    cub->ply.ply_y = i;
    cub->ply.ply_angle = 180;
}

void	east_info(t_cub *cub, int i, int j)
{
	cub->elements.E++;
	cub->ply.ply_x = j;
    cub->ply.ply_y = i;
    cub->ply.ply_angle = 0;
}

int check_info_of_player(t_cub *cub, int i, int j)
{
	if(cub->map.map[i][j] == 'N')
	{
		if(cub->elements.N != 0 || cub->elements.S != 0 || cub->elements.W != 0 || cub->elements.E != 0)
			return(1);
		north_info(cub, i, j);
	}
	if(cub->map.map[i][j] == 'S')
	{
		if(cub->elements.N != 0 || cub->elements.S != 0 || cub->elements.W != 0 || cub->elements.E != 0)
			return(1);
		cub->elements.S++;
		south_info(cub, i, j);
	}
	if(cub->map.map[i][j] == 'W')
	{
		if(cub->elements.N != 0 || cub->elements.S != 0 || cub->elements.W != 0 || cub->elements.E != 0)
			return(1);
		cub->elements.W++;
		west_info(cub, i, j);
	}
	if(cub->map.map[i][j] == 'E')
	{
		if(cub->elements.N != 0 || cub->elements.S != 0 || cub->elements.W != 0 || cub->elements.E != 0)
			return(1);
		cub->elements.E++;
		east_info(cub, i, j);
	}
	return(0);
}

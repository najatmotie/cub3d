/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:54 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 12:10:59 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	north_info(t_cub *cub, int i, int j)
{
	if (cub->elements.n != 0 || cub->elements.s != 0 || cub->elements.w != 0
		|| cub->elements.e != 0)
		return (false);
	cub->elements.n++;
	cub->ply.ply_x = j + 0.5;
	cub->ply.ply_y = i + 0.5;
	cub->ply.ply_angle = 90;
	return (true);
}

bool	south_info(t_cub *cub, int i, int j)
{
	if (cub->elements.n != 0 || cub->elements.s != 0 || cub->elements.w != 0
		|| cub->elements.e != 0)
		return (false);
	cub->elements.s++;
	cub->ply.ply_x = j + 0.5;
	cub->ply.ply_y = i + 0.5;
	cub->ply.ply_angle = 270;
	return (true);
}

bool	west_info(t_cub *cub, int i, int j)
{
	if (cub->elements.n != 0 || cub->elements.s != 0 || cub->elements.w != 0
		|| cub->elements.e != 0)
		return (false);
	cub->elements.w++;
	cub->ply.ply_x = j + 0.5;
	cub->ply.ply_y = i + 0.5;
	cub->ply.ply_angle = 180;
	return (true);
}

bool	east_info(t_cub *cub, int i, int j)
{
	if (cub->elements.n != 0 || cub->elements.s != 0 || cub->elements.w != 0
		|| cub->elements.e != 0)
		return (false);
	cub->elements.e++;
	cub->ply.ply_x = j + 0.5;
	cub->ply.ply_y = i + 0.5;
	cub->ply.ply_angle = 0;
	return (true);
}

int	check_info_of_player(t_cub *cub, int i, int j)
{
	if (cub->map.map[i][j] == 'N')
	{
		if (!north_info(cub, i, j))
			return (1);
	}
	if (cub->map.map[i][j] == 'S')
	{
		if (!south_info(cub, i, j))
			return (1);
	}
	if (cub->map.map[i][j] == 'W')
	{
		if (!west_info(cub, i, j))
			return (1);
	}
	if (cub->map.map[i][j] == 'E')
	{
		if (east_info(cub, i, j))
			return (1);
	}
	return (0);
}

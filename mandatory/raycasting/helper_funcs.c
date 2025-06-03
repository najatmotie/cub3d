/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:30 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/29 16:30:04 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	degree_to_radian(float angle)
{
	return (angle * M_PI / 180.0);
}

float	normalize_angle(float angle)
{
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

int	inside_bounds(t_cub cub, float x, float y)
{
	if (x >= 0 && x < cub.map.width && y >= 0 && y < cub.map.height)
		return (1);
	return (0);
}

float	calculate_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

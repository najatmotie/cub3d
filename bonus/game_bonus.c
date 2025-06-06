/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:49:59 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 13:33:17 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	esc_key(t_cub *cub)
{
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	mlx_close_window(cub->mlx.mlx_ptr);
}

void	game_loop(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		esc_key(cub);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
		forward_move(cub);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
		backward_move(cub);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
		left_move(cub);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
		right_move(cub);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
		cub->ply.ply_angle += ROTATION_SPEED;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
		cub->ply.ply_angle -= ROTATION_SPEED;
	cub->ply.ply_angle = normalize_angle(cub->ply.ply_angle);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.img_ptr, 0, 0);
	cast_rays(cub);
	draw_minimap(cub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:47:40 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 16:14:37 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		check_extension(av[1]);
		init_data(&cub);
		parsing_file(&cub, av[1]);
		cub.ray = malloc(WINDOW_WIDTH * sizeof(t_ray));
		if (!cub.ray)
			failure_handling(&cub, NULL, -1);
		cub.mlx.mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
		mlx_loop_hook(cub.mlx.mlx_ptr, game_loop, &cub);
		mlx_loop(cub.mlx.mlx_ptr);
		cleanup_ressources(&cub);
		mlx_terminate(cub.mlx.mlx_ptr);
	}
	else
	{
		write(2, "Invalid Arguments!\n", 19);
		return (1);
	}
	return (0);
}

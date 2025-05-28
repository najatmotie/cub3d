/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:47:40 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:20:39 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		check_file(av[1]);
		init_data(&cub);
		parsing_file(&cub, av[1]);
		cub.ray = malloc(SCREEN_WIDTH * sizeof(t_ray));
		if (cub.ray == NULL)
		{
			perror("malloc");
			return (1);
		}
		cub.mlx.mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", 0);
		mlx_loop_hook(cub.mlx.mlx_ptr, game_loop, &cub);
		mlx_loop(cub.mlx.mlx_ptr);
		cleanup_ressources(&cub);
		mlx_terminate(cub.mlx.mlx_ptr);
	}
	else
	{
		write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:39:41 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 13:01:20 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	check_file(char *file)
{
	char	*s;

	s = ft_strrchr(file, '.');
	if (s == NULL)
	{
		write(1, "Must Ending With The .ber\n", 26);
		exit(1);
	}
	if (ft_strcmp(s, ".cub") != 0)
	{
		write(1, "Must Ending With The .ber\n", 26);
		exit(1);
	}
}

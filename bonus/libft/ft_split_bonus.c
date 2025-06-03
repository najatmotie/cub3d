/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:51:24 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/29 16:37:27 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	*free_memory(char **result, int j)
{
	while (j >= 0)
	{
		if (result[j] != NULL)
			free(result[j]);
		j--;
	}
	free(result);
	return (NULL);
}

char	**reserve_memory(char **array, int words)
{
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	return (array);
}

char	*fill_word(char *s, int start, int end)
{
	int		i;
	char	*array;

	i = 0;
	array = malloc(sizeof(char) * (end - start + 1));
	if (array == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	while (start < end)
	{
		array[i] = s[start];
		i++;
		start++;
	}
	array[i] = '\0';
	return (array);
}

char	**fill_array(char *s, char c, int words)
{
	int		i;
	int		j;
	int		start;
	char	**array;

	i = 0;
	j = 0;
	start = 0;
	array = NULL;
	array = reserve_memory(array, words);
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[j] = fill_word(s, start, i);
		if (array[j] == NULL)
			return (free_memory(array, j));
		j++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**array;
	int		words_count;

	i = 0;
	words_count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words_count++;
		i++;
	}
	array = fill_array(s, c, words_count);
	if (array)
		return (array);
	return (NULL);
}

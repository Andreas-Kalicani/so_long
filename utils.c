/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:07 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/28 16:50:47 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

void	ft_double_pointer_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

char	**map_duplicate(t_game *data)
{
	int		i;
	int		j;
	char	**dupped_map;

	i = 0;
	dupped_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	while (i < data->map_height)
	{
		dupped_map[i] = (char *)malloc(sizeof(char) * (data->map_width + 1));
		j = 0;
		while (j < data->map_width)
		{
			if (data->map.map[i][j] == 'P' || data->map.map[i][j] == 'E'
				|| data->map.map[i][j] == 'C' || data->map.map[i][j] == '1')
				dupped_map[i][j] = data->map.map[i][j];
			else
				dupped_map[i][j] = 'F';
			j++;
		}
		dupped_map[i][j] = '\0';
		i++;
	}
	dupped_map[i] = NULL;
	return (dupped_map);
}

int	is_valid_move(t_game *data, char **map_dup, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height
		|| map_dup[y][x] == 'V')
		return (0);
	if (map_dup[y][x] == 'E' && data->map.coin_count == 0)
		return (0);
	if (map_dup[y][x] == 'P')
		return (1);
	if (map_dup[y][x] == 'F' || map_dup[y][x] == 'C' || map_dup[y][x] == 'E')
		return (check_coin_reach(data, map_dup, x, y));
	return (0);
}

void	destroy(t_game *data)
{
	ft_double_pointer_free(data->map.map);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

int	check_coin_reach(t_game *data, char **map_dup, int x, int y)
{
	int	left;
	int	right;
	int	up;
	int	down;

	map_dup[y][x] = 'V';
	left = is_valid_move(data, map_dup, x - 1, y);
	right = is_valid_move(data, map_dup, x + 1, y);
	up = is_valid_move(data, map_dup, x, y - 1);
	down = is_valid_move(data, map_dup, x, y + 1);
	return (left || right || up || down);
}

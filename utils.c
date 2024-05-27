/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:07 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/21 17:31:54 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

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
/*
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
*/

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
/*
int	check_if_player_can_reach_coin(t_game *data, char **map_dup, int x, int y)
{
	int	left;
	int	right;
	int	up;
	int	down;

	left = 0;
	right = 0;
	up = 0;
	down = 0;
	if (x >= data->map_width || y >= data->map_height || x < 0 || y < 0
		|| map_dup[y][x] == 'V')
		return (0);
	if (map_dup[y][x] == 'P')
		return (1);
	map_dup[y][x] = 'V';
	if (x > 0 && (map_dup[y][x - 1] == 'F' || map_dup[y][x - 1] == 'C'
			|| map_dup[y][x - 1] == 'E' || map_dup[y][x - 1] == 'P'))
		left = check_if_player_can_reach_coin(data, map_dup, x - 1, y);
	if (x < data->map_width - 1 && (map_dup[y][x + 1] == 'F' || map_dup[y][x
			+ 1] == 'C' || map_dup[y][x + 1] == 'E' || map_dup[y][x
			+ 1] == 'P'))
		right = check_if_player_can_reach_coin(data, map_dup, x + 1, y);
	if (y > 0 && (map_dup[y - 1][x] == 'F' || map_dup[y - 1][x] == 'C'
			|| map_dup[y - 1][x] == 'E' || map_dup[y - 1][x] == 'P'))
		up = check_if_player_can_reach_coin(data, map_dup, x, y - 1);
	if (y < data->map_height - 1 && (map_dup[y + 1][x] == 'F' || map_dup[y
			+ 1][x] == 'C' || map_dup[y + 1][x] == 'E' || map_dup[y
			+ 1][x] == 'P'))
		down = check_if_player_can_reach_coin(data, map_dup, x, y + 1);
	return (left || right || up || down);
}
*/
/*
int	check_if_player_can_reach_coin(t_game *data, char **map_dup, int x, int y)
{
	int	left;
	int	right;
	int	up;
	int	down;

	left = 0;
	right = 0;
	up = 0;
	down = 0;
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height
		|| map_dup[y][x] == 'V')
		return (0);
	if (map_dup[y][x] == 'P')
		return (1);
	map_dup[y][x] = 'V';
	if (x > 0 && (map_dup[y][x - 1] == 'F' || map_dup[y][x - 1] == 'C'
			|| map_dup[y][x - 1] == 'E' || map_dup[y][x - 1] == 'P'))
		left = check_if_player_can_reach_coin(data, map_dup, x - 1, y);
	if (x < data->map_width - 1 && (map_dup[y][x + 1] == 'F' || map_dup[y][x
			+ 1] == 'C' || map_dup[y][x + 1] == 'E' || map_dup[y][x
			+ 1] == 'P'))
		right = check_if_player_can_reach_coin(data, map_dup, x + 1, y);
	if (y > 0 && (map_dup[y - 1][x] == 'F' || map_dup[y - 1][x] == 'C'
			|| map_dup[y - 1][x] == 'E' || map_dup[y - 1][x] == 'P'))
		up = check_if_player_can_reach_coin(data, map_dup, x, y - 1);
	if (y < data->map_height - 1 && (map_dup[y + 1][x] == 'F' || map_dup[y
			+ 1][x] == 'C' || map_dup[y + 1][x] == 'E' || map_dup[y
			+ 1][x] == 'P'))
		down = check_if_player_can_reach_coin(data, map_dup, x, y + 1);
	return (left || right || up || down);
}
*/

int	is_valid_move(t_game *data, char **map_dup, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height
		|| map_dup[y][x] == 'V')
		return (0);
	if (map_dup[y][x] == 'P')
		return (1);
	if (map_dup[y][x] == 'F' || map_dup[y][x] == 'C' || map_dup[y][x] == 'E')
		return (check_if_player_can_reach_coin(data, map_dup, x, y));
	return (0);
}

void	destroy(t_game *data)
{
	ft_double_pointer_free(data->map.map);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

int	check_if_player_can_reach_coin(t_game *data, char **map_dup, int x, int y)
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

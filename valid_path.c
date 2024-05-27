/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:28:31 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/27 21:04:00 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"
int	count_coins(t_game *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	flood_fill(t_game *data, int x, int y, int *count_c)
{
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
		return ;
	if (data->map.map[y][x] == '1' || data->map.map[y][x] == 'E')
		return ;
	if (data->map.map[y][x] == 'C')
	{
		(*count_c)--;
		data->map.map[y][x] = '0';
		if (*count_c == 0)
		{
			data->map.map[y][x] = 'E';
		}
	}
	data->map.map[y][x] = 'E';
	if (data->map.map[y][x] == '0')
	{
		data->map.map[y][x] = 'E';
		flood_fill(data, (x + 1), y, count_c);
		flood_fill(data, (x - 1), y, count_c);
		flood_fill(data, x, (y + 1), count_c);
		flood_fill(data, x, (y - 1), count_c);
	}
	data->map.map[y][x] = '0';
}

void	decremet_c(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map.map[y][x] == 'C')
			{
				data->map.coin_count--;
				data->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

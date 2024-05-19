/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:28:31 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/16 21:24:03 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	count_c(t_game *data)
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
		data->map.coin_count--;
		data->map.map[y][x] = '0';
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

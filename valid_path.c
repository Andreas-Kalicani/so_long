/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:28:31 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/19 16:57:22 by akalican         ###   ########.fr       */
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
			{
				
				count++;
			}
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

/*void flood_fill(t_game *data, int x, int y, int *count_c)
{
    if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
        return;
    if (data->map.map[y][x] == '1' || data->map.map[y][x] == 'E')
        return;
    if (data->map.map[y][x] == 'C')
    {
        (*count_c)--;
		data->map.map[y][x] = '0';
    }
    data->map.map[y][x] = 'E';
    flood_fill(data, x + 1, y, count_c);
    flood_fill(data, x - 1, y, count_c);
    flood_fill(data, x, y + 1, count_c);
    flood_fill(data, x, y - 1, count_c);
}
*/
/*int flood_fill(t_game *data, int x, int y, int *count_c)
{
    if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
        return 1;
    if (data->map.map[y][x] == '1' || data->map.map[y][x] == 'E')
        return 1;
    if (data->map.map[y][x] == 'C')
    {
        // Check if the coin is surrounded by walls
        if ((x == 0 || data->map.map[y][x - 1] == '1') &&
            (x == data->map_width - 1 || data->map.map[y][x + 1] == '1') &&
            (y == 0 || data->map.map[y - 1][x] == '1') &&
            (y == data->map_height - 1 || data->map.map[y + 1][x] == '1'))
        {
            return 0;
        }
        (*count_c)--;
        data->map.map[y][x] = '0';
    }
    data->map.map[y][x] = 'E';
    return flood_fill(data, x + 1, y, count_c) &&
           flood_fill(data, x - 1, y, count_c) &&
           flood_fill(data, x, y + 1, count_c) &&
           flood_fill(data, x, y - 1, count_c);
}
*/
/*int check_map(t_game *data)
{
int *count_c = malloc(sizeof(int));
*count_c = data->map.coin_count;
if (!flood_fill(data, data->player.x, data->player.y, count_c))
{
    printf("Invalid map: a coin is surrounded by walls\n");
    exit(1);
}
free(count_c);
return (1);
}
*/
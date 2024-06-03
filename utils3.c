/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:07:01 by akalican          #+#    #+#             */
/*   Updated: 2024/06/03 09:44:50 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "mlx.h"


void	draw_texture(t_game *data, int pos[2])
{
	if (data->map.map[pos[1]][pos[0]] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->door_texture.textures, (1920 / 2) + (pos[0] * 15), (1080 / 2)
			+ (pos[1] * 15));
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (pos[0] * 15), (1080 / 2)
			+ (pos[1] * 15));
	}
}

void	check_coin(t_game *data)
{
	if (data->map.map[data->player.y][data->player.x] == 'C')
	{
		flood_fill(data, data->player.x, data->player.y, &data->map.coin_count);
	}
}
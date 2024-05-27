/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:34 by akalican          #+#    #+#             */
/*   Updated: 2024/05/27 21:51:42 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	move_up(t_game *data)
{
	int	old_x;
	int	old_y;
	int	count_c;

	if (data->map.map[data->player.y - 1]
		&& data->map.map[data->player.y - 1][data->player.x] != '1')
	{
		old_x = data->player.x;
		old_y = data->player.y;
		data->player.y -= 1;
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (old_x * 15), (1080 / 2)
			+ (old_y * 15));
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
		data->count_moves++;
		if (data->map.map[data->player.y][data->player.x] == 'C')
			flood_fill(data, data->player.x, data->player.y,
				&data->map.coin_count);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

void	move_down(t_game *data)
{
	int	pos[2];
	int	count_c;

	if (data->map.map[data->player.y + 1]
		&& data->player.y + 1 < data->map_height
		&& data->map.map[data->player.y + 1][data->player.x] != '1')
	{
		pos[0] = data->player.x;
		pos[1] = data->player.y;
		data->player.y += 1;
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (pos[0] * 15), (1080 / 2)
			+ (pos[1] * 15));
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
		data->count_moves++;
		if (data->map.map[data->player.y][data->player.x] == 'C')
			flood_fill(data, data->player.x, data->player.y,
				&data->map.coin_count);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

void	move_left(t_game *data)
{
	int	old_x;
	int	old_y;

	if (data->map.map[data->player.y][data->player.x - 1]
		&& data->map.map[data->player.y][data->player.x - 1] != '1')
	{
		old_x = data->player.x;
		old_y = data->player.y;
		data->player.x -= 1;
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
		data->count_moves++;
		if (data->map.map[data->player.y][data->player.x] == 'C')
			flood_fill(data, data->player.x, data->player.y,
				&data->map.coin_count);
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (old_x * 15), (1080 / 2)
			+ (old_y * 15));
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
	}
}

void	move_right(t_game *data)
{
	int	old_x;
	int	old_y;

	if (data->map.map[data->player.y + 1]
		&& data->map.map[data->player.y][data->player.x + 1] != '1')
	{
		old_x = data->player.x;
		old_y = data->player.y;
		data->player.x += 1;
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
		data->count_moves++;
		if (data->map.map[data->player.y][data->player.x] == 'C')
			flood_fill(data, data->player.x, data->player.y,
				&data->map.coin_count);
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (old_x * 15), (1080 / 2)
			+ (old_y * 15));
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (data->player.x * 15),
			(1080 / 2) + (data->player.y * 15));
	}
}

/*
int	character_moves(int key, t_game *data)
{
	if (key == w)
		move_up(data);
	if (key == s)
		move_down(data);
	if (key == a)
		move_left(data);
	if (key == d)
		move_right(data);
	if (key == ESC)
		destroy(data);
	if (data->map.coin_count == 0)
	{
		if (data->map.map[data->player.y][data->player.x] == 'E')
		{
			write(1, "game over!\n", 10);
			destroy(data);
		}
	}
	return (key);
} */

int	character_moves(int key, t_game *data)
{
    if (key == w)
        move_up(data);
    if (key == s)
        move_down(data);
    if (key == a)
        move_left(data);
    if (key == d)
        move_right(data);
    if (key == ESC)
        destroy(data);
    if (data->map.coin_count == 0)
    {
        if (data->map.map[data->player.y][data->player.x] == 'E')
        {
            write(1, "game over!\n", 10);
            destroy(data);
        }
    }
    return (key);
}
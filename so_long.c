/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:03 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/27 21:09:44 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./error.h"
#include "./libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

static void	print_elements_to_screen(t_game *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->wall_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y
				* 15));
	else if (data->map.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y
				* 15));
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->coin_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y
				* 15));
	else if (data->map.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures, (1920 / 2) + (x * 15), (1080 / 2)
			+ (y * 15));
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->door_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y
				* 15));
}


void	free_map(t_game *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}

int	close_window(t_game *data)
{
	ft_double_pointer_free(data->map.map);
	exit(0);
}

void	print_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			print_elements_to_screen(data, x, y);
			x++;
		}
		y++;
	}
}
void	move_player(t_game *data, int new_x, int new_y)
{
    if (data->map.map[new_y][new_x] == 'C')
    {
        data->map.map[new_y][new_x] = '0';
        data->map.coin_count--;
        if (data->map.coin_count == 0)
        {
            // Iterate over the map to find the hidden exit
            for (int y = 0; y < data->map.map_height; y++)
            {
                for (int x = 0; x < data->map.map_width; x++)
                {
                    if (data->map.map[y][x] == 'X')
                    {
                        // Replace the hidden exit with a visible exit
                        data->map.map[y][x] = 'E';
                        break;
                    }
                }
            }
        }
    }
    // Handle other cases (moving into a wall, moving into an empty space, etc.)
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (error(bad_args));
	ft_bzero(&data, sizeof(t_game));
	data.fd = open(argv[1], O_RDONLY);
	data.map_height = count_lines(argv[1]);
	data.map.map = parse(&data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	init_texture(&data);
	print_map(&data);
	mlx_hook(data.window, 17, 0, &close_window, &data);
	mlx_key_hook(data.window, &character_moves, &data);
	mlx_loop(data.mlx);
}

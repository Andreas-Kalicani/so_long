/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:13:40 by akalican          #+#    #+#             */
/*   Updated: 2024/05/27 18:25:07 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

void	init_texture(t_game *data)
{
	data->floor_texture.textures = mlx_xpm_file_to_image(data->mlx,
			"./sprites/black_floor.xpm", &(data->floor_texture.width),
			&(data->floor_texture.height));
	data->wall_texture.textures = mlx_xpm_file_to_image(data->mlx,
			"./sprites/wall.xpm", &(data->wall_texture.width),
			&(data->wall_texture.height));
	data->coin_texture.textures = mlx_xpm_file_to_image(data->mlx,
			"./sprites/coin.xpm", &(data->coin_texture.width),
			&(data->coin_texture.height));
	data->player_texture.textures = mlx_xpm_file_to_image(data->mlx,
			"./sprites/knight.xpm", &(data->wall_texture.width),
			&(data->wall_texture.height));
	data->door_texture.textures = mlx_xpm_file_to_image(data->mlx,
			"./sprites/door.xpm", &(data->door_texture.width),
			&(data->door_texture.height));
}

char	*read_and_trim_line(int fd)
{
	char	*buffer;
	char	*trimmed;

	buffer = get_next_line(fd);
	trimmed = ft_strtrim(buffer, " \n");
	free(buffer);
	return (trimmed);
}

void	process_line(t_game *data, char **return_value, char *buffer, int i)
{
	if ((int)ft_strlen(buffer) != data->map_width)
		exit(1);
	return_value[i] = ft_strdup(buffer);
	element_counter(data, buffer);
	free(buffer);
}

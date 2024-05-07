/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:03 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/07 15:28:14 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h>
#include "./error.h"
#include <fcntl.h>
#include "./libft/libft.h"

static void print_elements_to_screen(t_game *data, int x, int y)
{
    if (data->map.map[y][x] == '1')
        mlx_put_image_to_window(data->mlx, data->window, data->wall_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
    else if (data->map.map[y][x] == '0')
        mlx_put_image_to_window(data->mlx, data->window, data->floor_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
    else if (data->map.map[y][x] == 'C')
        mlx_put_image_to_window(data->mlx, data->window, data->coin_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
    else if (data->map.map[y][x] == 'P')
        mlx_put_image_to_window(data->mlx, data->window, data->player_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
    else if (data->map.map[y][x] == 'E')
        mlx_put_image_to_window(data->mlx, data->window, data->door_texture.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
}

void free_map(t_game *data)
{
    int i = 0;
    while (data->map.map[i])
    {
        free(data->map.map[i]);
        i++;
    }
    free(data->map.map);
}

int close_window(t_game *data)
{
    free_map(data);
    exit(0);
}

int main(int argc, char **argv)
{
    t_game  data;
    int     x;
    int     y;

    y = 0;
    if (argc != 2)
        return (error(bad_args));
    ft_bzero(&data, sizeof(t_game));
    data.fd = open(argv[1], O_RDONLY);
    data.map_height = count_lines(argv[1]);
    data.map.map = parse(&data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, 1920, 1080, "so_long");
    data.floor_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/black_floor.xpm", &(data.floor_texture.width), &(data.floor_texture.height));
    data.wall_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/wall.xpm", &(data.wall_texture.width), &(data.wall_texture.height));
    data.coin_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/coin.xpm", &(data.coin_texture.width), &(data.coin_texture.height));
    data.player_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/knight.xpm", &(data.wall_texture.width), &(data.wall_texture.height));
    data.door_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/door.xpm", &(data.door_texture.width), &(data.door_texture.height));
    while (data.map.map[y])
    {
        x = 0;
        while (data.map.map[y][x] && data.map.map[y][x] != '\n')
        {
            if (data.map.map[y][x] == 'P')
            {
                data.player.x = x;
                data.player.y = y;
            }
            print_elements_to_screen(&data, x, y);
            x++;
        }
        y++;
    }
    mlx_hook(data.window, 17, 0, &close_window, &data);
    mlx_key_hook(data.window, &character_moves, &data);
    mlx_loop(data.mlx);
}
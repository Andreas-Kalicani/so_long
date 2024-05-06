/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:03 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/06 18:42:07 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h>
#include "./error.h"
#include <fcntl.h>
#include "./libft/libft.h"

int main(int argc, char **argv)
{
    t_game  data;
    int     x;
    int     y;

    y = 0;
    if (argc != 2)
        return (error(bad_args));
    data.fd = open(argv[1], O_RDONLY);
    data.map_height = count_lines(argv[1]);
    data.map = parse(&data);
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, 1920, 1080, "so_long");
    data.floor_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/floor.xpm", &(data.floor_texture.width), &(data.floor_texture.height));
    data.wall_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/wall.xpm", &(data.wall_texture.width), &(data.wall_texture.height));
    data.coin_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/coin.xpm", &(data.coin_texture.width), &(data.coin_texture.height));
    data.player_texture.textures = mlx_xpm_file_to_image(data.mlx, "./sprites/knight.xpm", &(data.wall_texture.width), &(data.wall_texture.height));
    while (data.map[y])
    {
        x = 0;
        while (data.map[y][x] && data.map[y][x] != '\n')
        {
            if (data.map[y][x] == 'P')
            {
                data.px = x;
                data.py = y;
            }
            data.textures = mlx_xpm_file_to_image(data.mlx, get_image_path((data.map)[y][x]), &(data.width), &(data.height));
            mlx_put_image_to_window(data.mlx, data.window, data.textures, (1920 / 2) + (x * 15), (1080 / 2) + (y * 15));
            x++;
        }
        y++;
    }
    printf("this is on top of me ! : %c\n", data.map[data.py -1][data.px]);
    printf("this is below me ! : %c\n", data.map[data.py + 1][data.px]);
    printf("this is on my left ! : %c\n", data.map[data.py][data.px - 1]);
    printf("this is on my right ! : %c\n", data.map[data.py][data.px + 1]);
    mlx_key_hook(data.window, &character_moves, &data);
    mlx_loop(data.mlx);
}
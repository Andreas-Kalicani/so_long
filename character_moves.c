/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:34 by akalican          #+#    #+#             */
/*   Updated: 2024/05/07 15:04:19 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "../mlx/mlx.h"


void    move_up(t_game *data)
{
    
    if (data->map.map[data->player.y - 1][data->player.x] != '1')
    {
        data->player.y -= 1;
        mlx_put_image_to_window(data->mlx, data->window, data->player_texture.textures, (1920 / 2) + (data->player.x * 15), (1080 / 2) + (data->player.y * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map.map[data->player.y -1][data->player.x]);
        printf("this is below me ! : %c\n", data->map.map[data->player.y + 1][data->player.x]);
        printf("this is on my left ! : %c\n", data->map.map[data->player.y][data->player.x - 1]);
        printf("this is on my right ! : %c\n", data->map.map[data->player.y][data->player.x + 1]);
    }
}

void    move_down(t_game *data)
{
    if (data->map.map[data->player.y + 1][data->player.x] != '1')
    {
        data->player.y += 1;
        mlx_put_image_to_window(data->mlx, data->window, data->player_texture.textures, (1920 / 2) + (data->player.x * 15), (1080 / 2) + (data->player.y * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map.map[data->player.y -1][data->player.x]);
        printf("this is below me ! : %c\n", data->map.map[data->player.y + 1][data->player.x]);
        printf("this is on my left ! : %c\n", data->map.map[data->player.y][data->player.x - 1]);
        printf("this is on my right ! : %c\n", data->map.map[data->player.y][data->player.x + 1]);
    }
}

void    move_left(t_game *data)
{
    if (data->map.map[data->player.y][data->player.x - 1] != '1')
    {
        data->player.x -= 1;
        mlx_put_image_to_window(data->mlx, data->window, data->player_texture.textures, (1920 / 2) + (data->player.x * 15), (1080 / 2) + (data->player.y * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map.map[data->player.y -1][data->player.x]);
        printf("this is below me ! : %c\n", data->map.map[data->player.y + 1][data->player.x]);
        printf("this is on my left ! : %c\n", data->map.map[data->player.y][data->player.x - 1]);
        printf("this is on my right ! : %c\n", data->map.map[data->player.y][data->player.x + 1]);
    }
}
void    move_right(t_game *data)
{
    if (data->map.map[data->player.y][data->player.x + 1] != '1')
    {
        data->player.x += 1;
        mlx_put_image_to_window(data->mlx, data->window, data->player_texture.textures, (1920 / 2) + (data->player.x * 15), (1080 / 2) + (data->player.y * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map.map[data->player.y -1][data->player.x]);
        printf("this is below me ! : %c\n", data->map.map[data->player.y + 1][data->player.x]);
        printf("this is on my left ! : %c\n", data->map.map[data->player.y][data->player.x - 1]);
        printf("this is on my right ! : %c\n", data->map.map[data->player.y][data->player.x + 1]);
    }
}

void    destroy(t_game *data)
{
    mlx_destroy_window(data->mlx, data->window);
    exit(0);
}

int character_moves(int key, t_game *data)
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
    if (data->map.map[data->player.y][data->player.x] == 'E')
    {
        write(1, "game over!\n", 10);
        destroy(data);
    }
    printf("print data: %p\n", data);
    return (key);
}
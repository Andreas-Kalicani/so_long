/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:34 by akalican          #+#    #+#             */
/*   Updated: 2024/05/06 18:35:50 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "../mlx/mlx.h"


void    move_up(t_game *data)
{
    
    if (data->map[data->py - 1][data->px] != '1')
    {
        data->py -= 1;
        data->textures = mlx_xpm_file_to_image(data->mlx, "./sprites/knight.xpm", &(data->map_width), &(data->height));
        mlx_put_image_to_window(data->mlx, data->window, data->textures, (1920 / 2) + (data->px * 15), (1080 / 2) + (data->py * 15));
        data->textures = mlx_xpm_file_to_image(data->mlx, "./sprites/floor.xpm", &(data->width), &(data->height));
        mlx_put_image_to_window(data->mlx, data->window, data->textures, (1920 / 2) + (data->px * 15), (1080 / 2) + ((data->py + 1) * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map[data->py -1][data->px]);
        printf("this is below me ! : %c\n", data->map[data->py + 1][data->px]);
        printf("this is on my left ! : %c\n", data->map[data->py][data->px - 1]);
        printf("this is on my right ! : %c\n", data->map[data->py][data->px + 1]);
    }
}

void    move_down(t_game *data)
{
    if (data->map[data->py + 1][data->px] != '1')
    {
        data->py += 1;
        data->textures = mlx_xpm_file_to_image(data->mlx, "./sprites/knight.xpm", &(data->width), &(data->height));
        mlx_put_image_to_window(data->mlx, data->window, data->textures, (1920 / 2) + (data->px * 15), (1080 / 2) + (data->py * 15));
        data->textures = mlx_xpm_file_to_image(data->mlx, "./sprites/floor.xpm", &(data->width), &(data->height));
        mlx_put_image_to_window(data->mlx, data->window, data->textures, (1920 / 2) + ((data->px - 1) * 15), (1080 / 2) + (data->py * 15));
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map[data->py -1][data->px]);
        printf("this is below me ! : %c\n", data->map[data->py + 1][data->px]);
        printf("this is on my left ! : %c\n", data->map[data->py][data->px - 1]);
        printf("this is on my right ! : %c\n", data->map[data->py][data->px + 1]);
    }
}

void    move_left(t_game *data)
{
    if (data->map[data->py][data->px - 1] != '1')
    {
        data->px -= 1;
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map[data->py -1][data->px]);
        printf("this is below me ! : %c\n", data->map[data->py + 1][data->px]);
        printf("this is on my left ! : %c\n", data->map[data->py][data->px - 1]);
        printf("this is on my right ! : %c\n", data->map[data->py][data->px + 1]);
    }
}
void    move_right(t_game *data)
{
    if (data->map[data->py][data->px + 1] != '1')
    {
        data->px += 1;
        data->count_moves++;
        printf("this is on top of me ! : %c\n", data->map[data->py -1][data->px]);
        printf("this is below me ! : %c\n", data->map[data->py + 1][data->px]);
        printf("this is on my left ! : %c\n", data->map[data->py][data->px - 1]);
        printf("this is on my right ! : %c\n", data->map[data->py][data->px + 1]);
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
    printf("print data: %p\n", data);
    return (key);
}
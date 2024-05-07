/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:29 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/07 14:15:35 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include "./libft/libft.h"

enum    key {
    w = 13,
    a = 0,
    s = 1,
    d = 2,
    ESC = 53
};

enum    texture {
    player = 'P',
    wall = '1',
    floor = '0',
    coin = 'C',
    door = 'E'
};

typedef struct s_coord {
    int x;
    int y;
}       t_coord;

typedef struct s_texture {
    void    *textures;
    int     width;
    int     height;
}               t_texture;

typedef struct s_map {
    char    **map;
    int     map_height;
    int     map_width;
    int     coin_count;
    int     exit_count;
    int     player_count;
}               t_map;

typedef struct s_game {
    int     fd;
    void    *mlx;
    void    *window;
    t_texture    player_texture;
    t_texture    floor_texture;
    t_texture    wall_texture;
    t_texture    coin_texture;
    t_texture    door_texture;
    t_map   map;
    int     map_height;
    int     map_width;
    int     count_moves;
    t_coord player;
}               t_game;


int count_lines(char *path);
char **parse(t_game *data);
char    **map_parse(char *path);
int character_moves(int key, t_game *data);
#endif
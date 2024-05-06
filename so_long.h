/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:29 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/05/06 18:35:36 by akalican         ###   ########.fr       */
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

typedef struct s_coord {
    int x;
    int y;
}       t_coord;

typedef struct s_texture {
    void    *textures;
    int     width;
    int     height;
}               t_texture;

typedef struct s_game {
    int     fd;
    void    *mlx;
    void    *window;
    int    width;
    int    height;
    int     py;
    int     px;
    void    *textures;
    t_texture    player_texture;
    t_texture    floor_texture;
    t_texture    wall_texture;
    t_texture    coin_texture;
    t_texture    exit_texture;
    char     **map;
    int     map_height;
    int     map_width;
    int     count_moves;
    t_coord player;
}               t_game;


int count_lines(char *path);
char **parse(t_game *data);
char    **map_parse(char *path);
char *get_image_path(char tile);
int character_moves(int key, t_game *data);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:29 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/04/30 14:22:11 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include "./libft/libft.h"

typedef struct s_coord {
    int x;
    int y;
}       t_coord;

typedef struct s_game {
    int **map;
    int height;
    int width;
    t_coord player;
    int     player_up;
    int     player_down;
    int     player_left;
    int     player_right;
    int     player_move;
    t_coord exit;
    t_coord *coll;
    int       count_moves;
    int        count_exit;
}               t_game;


int count_lines(char *path);
#endif
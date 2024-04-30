/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:06:50 by akalican          #+#    #+#             */
/*   Updated: 2024/04/30 14:56:48 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<fcntl.h>
#include <stdio.h>

int count_lines(char *path)
{
    int fd;
    int number_of_lines;
    fd = open(path, O_RDONLY);
    char *read;
    read = get_next_line(fd);
    number_of_lines = 0;
    while (read != NULL)
    {
        free(read);
        number_of_lines++;
        read = get_next_line(fd);
    }
    close(fd);
    return (number_of_lines);
}

char    **map_parse(char *path)
{
    int i;
    int fd;
    
    i = 0;
    fd = open(path, O_RDONLY);
    int n = count_lines(path);
    char **map = ft_calloc(n + 1, sizeof(char *));
    map[n] = NULL;
    while (i < n)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    return (map);
}

char *get_image_path(char tile)
{
    switch (tile)
    {
        case '0':
            return "";
        case '1':
            return "./sprites/platforms.xpm";
        case 'C':
            return "./sprites/coin.xpm";
        default:
            return (NULL);
    }
}

int main()
{
    int i;

    i = 0;
    char **map = map_parse("./map/map_empty_line.ber");
    while (map[i] != NULL)
    {
        printf("Line %i : %s\n", i, map[i]);
        i++;
    }

    int x = 1;
    int y = 3;
    printf("Point at (%i;%i) is %c\n", x, y, map[y][x]);
}
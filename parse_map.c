/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:06:50 by akalican          #+#    #+#             */
/*   Updated: 2024/05/06 15:29:54 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<fcntl.h>
#include <stdio.h>
#include "./libft/libft.h"

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

char **parse(t_game *data)
{
    char    *buffer;
    int     i;
    char     **return_value;

    i = 0;
    return_value = (char **) malloc(sizeof(char *) * data->map_height);
    buffer = get_next_line(data->fd);
    while (buffer)
    {
        return_value[i] = buffer;
        i++;
        buffer = get_next_line(data->fd);
    }
    return (return_value);
}


char *get_image_path(char tile)
{
    switch (tile)
    {
        case '0':
            return "./sprites/floor.xpm";
        case '1':
            return "./sprites/wall.xpm";
        case 'C':
            return "./sprites/coin.xpm";
        case 'P':
            return "./sprites/knight.xpm";
        default:
            return (NULL);
    }
}

// int main()
// {
//     int     i;
//     t_game  data;

//     i = 0;
//     data.map = parse(&data);
//     while (data.map[i])
//     {
//         printf("Line %i : %i\n", i, data.map[i]);
//         i++;
//     }

//     int x = 1;
//     int y = 3;
//     printf("Point at (%i;%i) is %c\n", x, y, data.map[y][x]);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:06:50 by akalican          #+#    #+#             */
/*   Updated: 2024/05/19 16:36:56 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	count_lines(char *path)
{
	int		fd;
	int		number_of_lines;
	char	*read;

	fd = open(path, O_RDONLY);
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

// char    **map_parse(char *path)
// {
//     int i;
//     int fd;

//     i = 0;
//     fd = open(path, O_RDONLY);
//     int n = count_lines(path);
//     char **map = ft_calloc(n + 1, sizeof(char *));
//     map[n] = NULL;
//     while (i < n)
//     {
//         map[i] = get_next_line(fd);
//         i++;
//     }
//     return (map);
// }

// int check_if_rectangle(int fd)
// {

// }

// int is_valid_map(t_game *data)
// {

// }

void	element_counter(t_game *data, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			data->map.player_count++;
		if (buffer[i] == 'C')
			data->map.coin_count++;
		if (buffer[i] == 'E')
			data->map.exit_count++;
		i++;
	}
}

int	check_if_coins_are_exaccesible(t_game *data)
{
	int	i;
	int	j;
	int	wall_count;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map.map[i][j] == 'C')
			{
				wall_count = 0;
				if (i > 0 && data->map.map[i - 1][j] == '1')
					wall_count++;
				if (i < data->map_height - 1 && data->map.map[i + 1][j] == '1')
					wall_count++;
				if (j > 0 && data->map.map[i][j - 1] == '1')
					wall_count++;
				if (j < data->map_width - 1 && data->map.map[i][j + 1] == '1')
					wall_count++;
				if (wall_count >= 4)
				{
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_door_sourneded_by_wall(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map.map[i][j] == 'E')
			{
				if (i > 0 && i < data->map_height - 1 && j > 0
					&& j < data->map_width - 1 && data->map.map[i][j - 1] == '1'
					&& data->map.map[i][j + 1] == '1' && data->map.map[i
					- 1][j] == '1' && data->map.map[i + 1][j] == '1')
				{
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_checker(t_game *data)
{
	if (data->map.player_count != 1)
		return (0);
	if (data->map.coin_count < 1)
		return (0);
	if (data->map.exit_count != 1)
		return (0);
	if (check_if_door_sourneded_by_wall(data))
		exit(1);
	if (check_if_coins_are_exaccesible(data))
		exit(1);
	return (1);
}

// check if is rectangle and square:DONE
// check if surrounded by walls: DONE
// check if all coins and exit are reachable
// check if there is no leaks
// change all the exit to E to free() them

char	**parse(t_game *data)
{
	char	*buffer;
	int		i;
	char	**return_value;

	i = 0;
	return_value = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	buffer = get_next_line(data->fd);
	buffer = ft_strtrim(buffer, " \n");
	data->map_width = ft_strlen(buffer);
	while (buffer)
	{
		if ((int)ft_strlen(buffer) != data->map_width)
			exit(1);
		return_value[i] = ft_strdup(buffer);
		element_counter(data, buffer);
		free(buffer);
		buffer = get_next_line(data->fd);
		buffer = ft_strtrim(buffer, " \n");
		i++;
	}
	return_value[i] = NULL;
	data->map.map = return_value;
	if (!map_checker(data))
		exit(1);
	if (data->map_height == data->map_width)
		exit(1);
	return (return_value);
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

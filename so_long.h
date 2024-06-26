/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:29 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/06/03 09:50:10 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./libft/libft.h"

enum			key
{
	w = 13,
	a = 0,
	s = 1,
	d = 2,
	ESC = 53
};

enum			texture
{
	player = 'P',
	wall = '1',
	floor = '0',
	coin = 'C',
	door = 'E'
};

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_texture
{
	void		*textures;
	int			width;
	int			height;
}				t_texture;

typedef struct s_map
{
	char		**map;
	int			map_height;
	int			map_width;
	int			coin_count;
	int			exit_count;
	int			player_count;
}				t_map;

typedef struct s_game
{
	int			fd;
	void		*mlx;
	void		*window;
	t_texture	player_texture;
	t_texture	floor_texture;
	t_texture	wall_texture;
	t_texture	coin_texture;
	t_texture	door_texture;
	t_map		map;
	int			map_height;
	int			map_width;
	int			count_moves;
	t_coord		player;
}				t_game;

int				count_lines(char *path);
char			**parse(t_game *data);
char			**map_parse(char *path);
int				character_moves(int key, t_game *data);
int				map_checker(t_game *data);
int				count_coins(t_game *data);
void			flood_fill(t_game *data, int x, int y, int *count_c);
// int 			flood_fill(t_game *data, int x, int y, int *count_c);
int				check_map(t_game *data);
char			**map_duplicate(t_game *data);
int				check_coin_reach(t_game *data, char **map_dup, int x, int y);
void			ft_double_pointer_free(char **pointer);
int				close_window(t_game *data);
// static void		print_elements_to_screen(t_game *data, int x, int y);
void			free_map(t_game *data);
int				is_valid_move(t_game *data, char **map_dup, int x, int y);
int				if_all_coin_collected_can_exit(t_game *data);
void			decremet_c(t_game *data);
void			destroy(t_game *data);
void			init_texture(t_game *data);
char			*read_and_trim_line(int fd);
void			process_line(t_game *data, char **return_value, char *buffer,
					int i);
void			element_counter(t_game *data, char *buffer);
void			draw_texture(t_game *data, int pos[2]);
void			check_coin(t_game *data);
#endif

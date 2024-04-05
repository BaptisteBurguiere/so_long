/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:27:37 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/06 00:47:24 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>

# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WALL '1'
# define EMPTY '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define FILL '2'

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	player[2];
	size_t	nb_items;
}	t_map;

typedef struct s_check_map_vars
{
	bool	is_player;
	bool	is_item;
	bool	is_exit;
	size_t	x;
	size_t	y;
}	t_check_map_vars;

typedef struct s_floodfill_vars
{
	size_t	i;
	size_t	j;
	bool	is_exit;
}	t_floodfill_vars;

// Map parser

t_map	*map_parse(int argc, char **argv);
bool	check_file(char *file_path);
bool	fill_map(t_map *map, int file_fd);
bool	check_line(char *line, t_map *map, size_t i, t_check_map_vars *vars);
bool	floodfill(t_map *map);

// Utils

void	print_error(char *err);
bool	return_error(char *err);
char	*get_next_line(int fd);
void	destroy_map(t_map *map);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:27:37 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/10 14:47:39 by bburguie         ###   ########.fr       */
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

# define FLOOR '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define FILL 'Z'
# define TEXTURE_TOP_WALL "textures/top_wall.png"
# define TEXTURE_BOTTOM_WALL "textures/bottom_wall.png"
# define TEXTURE_LEFT_WALL "textures/left_wall.png"
# define TEXTURE_RIGHT_WALL "textures/right_wall.png"
# define TEXTURE_FULL_WALL "textures/wall_full.png"
# define TEXTURE_BOTTOM_RIGHT_WALL "textures/bottom_right_wall.png"
# define TEXTURE_BOTTOM_LEFT_WALL "textures/bottom_left_wall.png"
# define TEXTURE_R_BOTTOM_RIGHT_WALL "textures/reverse_bottom_right_wall.png"
# define TEXTURE_R_BOTTOM_LEFT_WALL "textures/reverse_bottom_left_wall.png"
# define TEXTURE_FLOOR "textures/floor.png"
# define TEXTURE_ITEM "textures/item.png"
# define TEXTURE_PLAYER "textures/player.png"
# define TEXTURE_EXIT_CLOSE "textures/exit_closed.png"
# define TEXTURE_EXIT_OPEN "textures/exit_opened.png"
# define MAX_WIDTH 1920
# define MAX_HEIGHT 994
# define BLOCK_SIZE 64

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

typedef struct s_texture
{
	size_t			width;
	size_t			height;
	unsigned long	**tab;
}	t_texture;

typedef struct s_view_vars
{
	t_texture	t_wall;
	t_texture	b_wall;
	t_texture	l_wall;
	t_texture	r_wall;
	t_texture	f_wall;
	t_texture	br_wall;
	t_texture	bl_wall;
	t_texture	r_br_wall;
	t_texture	r_bl_wall;
	t_texture	floor;
	t_texture	player;
	t_texture	item;
	t_texture	exit_o;
	t_texture	exit_c;
	mlx_t		*mlx;
	mlx_image_t	*img;
	size_t		width;
	size_t		height;
}	t_view_vars;

typedef enum e_wall
{
	wall_top = '1',
	wall_bottom = '2',
	wall_left = '3',
	wall_right = '4',
	wall_full = '5',
	wall_bottom_right = '6',
	wall_bottom_left = '7',
	wall_r_bottom_right = '8',
	wall_r_bottom_left = '9',
}	t_wall;

// Map parser

t_map		*map_parse(int argc, char **argv);
bool		check_file(char *file_path);
bool		fill_map(t_map *map, int file_fd);
bool		check_line(char *line, t_map *map, size_t i,
				t_check_map_vars *vars);
bool		floodfill(t_map *map);

// Utils

void		print_error(char *err);
bool		return_error(char *err);
char		*get_next_line(int fd);
void		destroy_map(t_map *map);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
bool		is_wall(char c);

// View

bool		init_view(t_view_vars *vars, t_map *map);
void		destroy_view(t_view_vars *vars);
bool		load_textures(t_view_vars *vars);
void		destroy_texture(t_texture *texture);
void		display_map(t_view_vars *vars, t_map *map);
void		display_player(t_view_vars *vars, size_t player[2]);
t_texture	*get_texture(t_view_vars *vars, t_map *map, size_t x, size_t y);

#endif
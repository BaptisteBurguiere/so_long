/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:42:03 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/09 16:59:42 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_top_bottom(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	check_char(size_t x, size_t y, t_map *map, t_check_map_vars *vars)
{
	if (map->map[y][x] == PLAYER)
	{
		if (vars->is_player)
			return (return_error(
					"so_long Error:\nMultiple player start positions\n"));
		vars->is_player = true;
		map->player[0] = vars->x;
		map->player[1] = vars->y;
		map->map[y][x] = FLOOR;
	}
	else if (map->map[y][x] == EXIT)
	{
		if (vars->is_exit)
			return (return_error("so_long Error:\nMultiple exits\n"));
		vars->is_exit = true;
	}
	else if (map->map[y][x] == ITEM)
	{
		map->nb_items += 1;
		vars->is_item = true;
	}
	else if (map->map[y][x] != WALL && map->map[y][x] != FLOOR)
		return (return_error("so_long Error:\nInvalid character\n"));
	return (true);
}

bool	check_line(char *line, t_map *map, size_t i, t_check_map_vars *vars)
{
	size_t	j;

	if (ft_strlen(line) != map->width)
		return (return_error("so_long Error:\nMap must be rectangular\n"));
	if (i == 0 || i == map->height - 1)
	{
		if (!check_top_bottom(line))
		{
			print_error("so_long Error:\nMap must be framed by walls\n");
			return (false);
		}
		return (true);
	}
	if (line[0] != WALL || line[ft_strlen(line) - 1] != WALL)
		return (return_error("so_long Error:\nMap must be framed by walls\n"));
	j = 1;
	while (line[j])
	{
		vars->x = j;
		vars->y = i;
		if (!check_char(j, i, map, vars))
			return (false);
		j++;
	}
	return (true);
}

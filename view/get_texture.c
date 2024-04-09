/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:40:22 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/09 18:16:49 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	*wall_frame_y(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	if (y == 0)
	{
		if (x == 0)
			return (&(vars->l_wall));
		else if (x == map->width - 1)
			return (&(vars->r_wall));
		if (map->map[y + 1][x] != WALL)
			return (&(vars->t_wall));
		return (&(vars->f_wall));
	}
	else if (y == map->height - 1)
	{
		if (x == 0)
			return (&(vars->bl_wall));
		if (x == map->width - 1)
			return (&(vars->br_wall));
		if (map->map[y - 1][x] != WALL)
			return (&(vars->b_wall));
		return (&(vars->f_wall));
	}
	return (NULL);
}

t_texture	*wall_frame(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	if (y == 0 || y == map->height - 1)
		return (wall_frame_y(vars, map, x, y));
	if (x == 0)
	{
		if (map->map[y][x + 1] != WALL)
			return (&(vars->l_wall));
		return (&(vars->f_wall));
	}
	else if (x == map->width - 1)
	{
		if (map->map[y][x - 1] != WALL)
			return (&(vars->r_wall));
		return (&(vars->f_wall));
	}
	return (NULL);
}

t_texture	*get_texture_wall(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
		return (wall_frame(vars, map, x, y));
	return (NULL);
}

t_texture	*get_texture(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	if (map->map[y][x] == FLOOR)
		return (&(vars->floor));
	else if (map->map[y][x] == EXIT && map->nb_items > 0)
		return (&(vars->exit_c));
	else if (map->map[y][x] == EXIT)
		return (&(vars->exit_o));
	else if (map->map[y][x] == ITEM)
		return (&(vars->item));
	else if (map->map[y][x] == PLAYER)
		return (&(vars->player));
	else if (map->map[y][x] == WALL)
		return (get_texture_wall(vars, map, x, y));
	return (NULL);
}

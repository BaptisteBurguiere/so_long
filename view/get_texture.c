/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:40:22 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/10 14:17:48 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	*get_texture_wall(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	if (map->map[y][x] == wall_top)
		return (&(vars->t_wall));
	if (map->map[y][x] == wall_bottom)
		return (&(vars->b_wall));
	if (map->map[y][x] == wall_left)
		return (&(vars->l_wall));
	if (map->map[y][x] == wall_right)
		return (&(vars->r_wall));
	if (map->map[y][x] == wall_full)
		return (&(vars->f_wall));
	if (map->map[y][x] == wall_bottom_right)
		return (&(vars->br_wall));
	if (map->map[y][x] == wall_bottom_left)
		return (&(vars->bl_wall));
	if (map->map[y][x] == wall_r_bottom_right)
		return (&(vars->r_br_wall));
	if (map->map[y][x] == wall_r_bottom_left)
		return (&(vars->r_bl_wall));
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
	else if (is_wall(map->map[y][x]))
		return (get_texture_wall(vars, map, x, y));
	return (NULL);
}

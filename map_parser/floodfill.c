/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:18:26 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/06 01:07:29 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_next(char **map, size_t x, size_t y)
{
	if (map[y][x] == EMPTY || map[y][x] == ITEM)
		map[y][x] = FILL;
	if (map[y - 1][x] == EMPTY || map[y - 1][x] == ITEM)
		check_next(map, x, y - 1);
	if (map[y + 1][x] == EMPTY || map[y + 1][x] == ITEM)
		check_next(map, x, y + 1);
	if (map[y][x - 1] == EMPTY || map[y][x - 1] == ITEM)
		check_next(map, x - 1, y);
	if (map[y][x + 1] == EMPTY || map[y][x + 1] == ITEM)
		check_next(map, x + 1, y);
}

static bool	check_char(char **map_dup, t_floodfill_vars *vars)
{
	if (map_dup[vars->i][vars->j] == ITEM)
		return (return_error("so_long Error:\nImpossible to access an item\n"));
	else if (map_dup[vars->i][vars->j] == EXIT)
	{
		if (map_dup[vars->i - 1][vars->j] == FILL
			|| map_dup[vars->i - 1][vars->j] == PLAYER)
			vars->is_exit = true;
		else if (map_dup[vars->i + 1][vars->j] == FILL
			|| map_dup[vars->i + 1][vars->j] == PLAYER)
			vars->is_exit = true;
		else if (map_dup[vars->i][vars->j - 1] == FILL
			|| map_dup[vars->i][vars->j - 1] == PLAYER)
			vars->is_exit = true;
		else if (map_dup[vars->i][vars->j + 1] == FILL
			|| map_dup[vars->i][vars->j - 1] == PLAYER)
			vars->is_exit = true;
		if (!vars->is_exit)
		{
			print_error("so_long Error:\nImpossible to access the exit\n");
			return (false);
		}
	}
	return (true);
}

static bool	check_map_dup(t_map *map, char **map_dup)
{
	t_floodfill_vars	vars;

	vars.is_exit = false;
	vars.i = 1;
	while (vars.i < map->height)
	{
		vars.j = 1;
		while (vars.j < map->width)
		{
			if (!check_char(map_dup, &vars))
				return (false);
			vars.j += 1;
		}
		vars.i += 1;
	}
	return (true);
}

bool	floodfill(t_map *map)
{
	char	**map_dup;
	size_t	i;
	bool	ret;

	map_dup = malloc(map->height * sizeof(char *));
	i = 0;
	while (i < map->height)
	{
		map_dup[i] = ft_strdup(map->map[i]);
		i++;
	}
	check_next(map_dup, map->player[0], map->player[1]);
	ret = check_map_dup(map, map_dup);
	i = 0;
	while (i < map->height)
	{
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
	return (ret);
}

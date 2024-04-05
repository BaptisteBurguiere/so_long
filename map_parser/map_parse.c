/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:17:57 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/05 18:51:58 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_usage(void)
{
	print_error("so_long Error:\nWrong usage: bad number of arguments.\n");
	print_error("so_long: Usage: ./so_long map_path.ber\n");
}

bool	check_map(t_map *map)
{
	t_check_map_vars	vars;
	size_t				i;

	vars.is_player = false;
	vars.is_item = false;
	vars.is_exit = false;
	if (map->height < 1)
	{
		print_error("so_long Error:\nMap file empty\n");
		return (false);
	}
	map->width = ft_strlen(map->map[0]);
	i = 0;
	while (i < map->height)
	{
		if (!check_line(map->map[i], map, i, &vars))
			return (false);
		i++;
	}
	return (true);
}

t_map	*parse_file(char *file_path)
{
	t_map	*map;
	int		file_fd;

	file_fd = open(file_path, O_RDONLY);
	map = malloc(1 * sizeof(t_map));
	if (!fill_map(map, file_fd))
	{
		print_error("so_long Error:\nInvalid characters ");
		print_error("at the end of the map\n");
		destroy_map(map);
		return (NULL);
	}
	if (!check_map(map))
	{
		destroy_map(map);
		return (NULL);
	}
	return (map);
}

t_map	*map_parse(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		print_usage();
		return (NULL);
	}
	if (!check_file(argv[1]))
		return (NULL);
	map = parse_file(argv[1]);
	if (!map)
		return (NULL);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:38:30 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/05 18:46:37 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_line_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

static char	*remove_nl(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	return (line);
}

bool	fill_map(t_map *map, int file_fd)
{
	char	*line;

	map->map = malloc(10000 * sizeof(char *));
	map->height = 0;
	line = get_next_line(file_fd);
	while (line && is_line_empty(line))
	{
		free(line);
		line = get_next_line(file_fd);
	}
	while (line && !is_line_empty(line))
	{
		map->map[map->height] = remove_nl(line);
		map->height += 1;
		line = get_next_line(file_fd);
	}
	while (line && is_line_empty(line))
	{
		free(line);
		line = get_next_line(file_fd);
	}
	if (line != NULL)
		return (false);
	free(line);
	return (true);
}

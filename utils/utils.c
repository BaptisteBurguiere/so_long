/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:18:33 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/05 18:58:28 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *err)
{
	size_t	i;

	i = 0;
	while (err[i])
	{
		write(STDERR_FILENO, &err[i], 1);
		i++;
	}
}

bool	return_error(char *err)
{
	print_error(err);
	return (false);
}

char	*get_next_line(int fd)
{
	int		rd;
	char	c;
	char	*buf;
	int		i;

	i = 0;
	buf = malloc(100000);
	if (!buf)
		return (NULL);
	rd = read(fd, &c, 1);
	while (rd > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	buf[i] = '\0';
	if (rd == -1 || i == 0 || (!buf[i - 1] && !rd))
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

void	destroy_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

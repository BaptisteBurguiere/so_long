/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:35:37 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/05 18:53:20 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_ber(char *file_path)
{
	size_t	i;

	i = 0;
	while (file_path[i])
		i++;
	if (i < 4)
		return (false);
	if (file_path[i - 1] != 'r')
		return (false);
	if (file_path[i - 2] != 'e')
		return (false);
	if (file_path[i - 3] != 'b')
		return (false);
	if (file_path[i - 4] != '.')
		return (false);
	return (true);
}

bool	check_file(char *file_path)
{
	int	file_fd;

	if (!check_ber(file_path))
	{
		print_error("so_long Error:\nBad map format: ");
		print_error("map needs to be a .ber file\n");
		return (false);
	}
	file_fd = open(file_path, O_RDONLY);
	if (file_fd < 0)
	{
		print_error("so_long Error:\nCannot open map file '");
		print_error(file_path);
		print_error("'\n");
		return (false);
	}
	close(file_fd);
	return (true);
}

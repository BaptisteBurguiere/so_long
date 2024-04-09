/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:02:05 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/09 17:40:42 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

unsigned long	get_color(size_t x, size_t y, t_texture *texture)
{
	size_t	i;
	size_t	j;

	i = (size_t)(((float)y / (float)BLOCK_SIZE)
			* (float)texture->height);
	j = (size_t)(((float)x / (float)BLOCK_SIZE)
			* (float)texture->width);
	return (texture->tab[i][j]);
}

void	display_elt(t_view_vars *vars, t_map *map, size_t x, size_t y)
{
	size_t			i;
	size_t			j;
	unsigned long	color;

	i = y * BLOCK_SIZE;
	while (i - (y * BLOCK_SIZE) < BLOCK_SIZE)
	{
		j = x * BLOCK_SIZE;
		while (j - (x * BLOCK_SIZE) < BLOCK_SIZE)
		{
			color = get_color(j - (x * BLOCK_SIZE),
					i - (y * BLOCK_SIZE), get_texture(vars, map, x, y));
			if (color == 0)
			{
				color = get_color(j - (x * BLOCK_SIZE),
						i - (y * BLOCK_SIZE), &(vars->floor));
			}
			mlx_put_pixel(vars->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	display_player(t_view_vars *vars, size_t player[2])
{
	size_t			i;
	size_t			j;
	unsigned long	color;

	i = player[1] * BLOCK_SIZE;
	while (i - (player[1] * BLOCK_SIZE) < BLOCK_SIZE)
	{
		j = player[0] * BLOCK_SIZE;
		while (j - (player[0] * BLOCK_SIZE) < BLOCK_SIZE)
		{
			color = get_color(j - (player[0] * BLOCK_SIZE),
					i - (player[1] * BLOCK_SIZE), &(vars->player));
			if (color > 0)
				mlx_put_pixel(vars->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	display_map(t_view_vars *vars, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			display_elt(vars, map, j, i);
			j++;
		}
		i++;
	}
}

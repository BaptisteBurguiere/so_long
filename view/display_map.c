/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:02:05 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/11 16:10:18 by bburguie         ###   ########.fr       */
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

void	display_player(t_view_vars *vars, t_player player)
{
	size_t			i;
	size_t			j;
	unsigned long	color;
	t_texture		*texture;

	if (player.dir == 'r')
		texture = &(vars->player_right);
	else
		texture = &(vars->player_left);
	i = player.y * BLOCK_SIZE;
	while (i - (player.y * BLOCK_SIZE) < BLOCK_SIZE)
	{
		j = player.x * BLOCK_SIZE;
		while (j - (player.x * BLOCK_SIZE) < BLOCK_SIZE)
		{
			color = get_color(j - (player.x * BLOCK_SIZE),
					i - (player.y * BLOCK_SIZE), texture);
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

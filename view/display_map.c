/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:02:05 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/12 15:30:05 by bburguie         ###   ########.fr       */
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

	i = (y - vars->camera[1]) * BLOCK_SIZE;
	while (i - ((y - vars->camera[1]) * BLOCK_SIZE) < BLOCK_SIZE)
	{
		j = (x - vars->camera[0]) * BLOCK_SIZE;
		while (j - ((x - vars->camera[0]) * BLOCK_SIZE) < BLOCK_SIZE)
		{
			color = get_color(j - ((x - vars->camera[0]) * BLOCK_SIZE),
					i - ((y - vars->camera[1]) * BLOCK_SIZE), get_texture(vars, map, x, y));
			if (color == 0)
			{
				color = get_color(j - ((x - vars->camera[0]) * BLOCK_SIZE),
						i - ((y - vars->camera[1]) * BLOCK_SIZE), &(vars->floor));
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
	i = (player.y - vars->camera[1]) * BLOCK_SIZE;
	while (i - ((player.y - vars->camera[1]) * BLOCK_SIZE) < BLOCK_SIZE)
	{
		j = (player.x - vars->camera[0]) * BLOCK_SIZE;
		while (j - ((player.x - vars->camera[0]) * BLOCK_SIZE) < BLOCK_SIZE)
		{
			color = get_color(j - ((player.x - vars->camera[0]) * BLOCK_SIZE),
					i - ((player.y - vars->camera[1]) * BLOCK_SIZE), texture);
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

	i = vars->camera[1];
	while (i < vars->block_height + vars->camera[1])
	{
		j = vars->camera[0];
		while (j < vars->block_width + vars->camera[0])
		{
			display_elt(vars, map, j, i);
			j++;
		}
		i++;
	}
}

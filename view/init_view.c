/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:34:59 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/09 14:03:43 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	init_view(t_view_vars *vars)
{
	if (!load_textures(vars))
		return (false);
	vars->mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (!vars->mlx)
		return (false);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		return (false);
	if (mlx_image_to_window(vars->mlx, vars->img, 0, 0) == -1)
		return (false);
	return (true);
}

void	destroy_view(t_view_vars *vars)
{
	// destroy_texture(&(vars->exit));
	// destroy_texture(&(vars->floor));
	// destroy_texture(&(vars->item));
	// destroy_texture(&(vars->player));
	destroy_texture(&(vars->wall));
	mlx_delete_image(vars->mlx, vars->img);
	mlx_terminate(vars->mlx);
}

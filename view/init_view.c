/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:34:59 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/11 17:30:16 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_size(t_view_vars *vars, t_map *map)
{
	if (map->width * BLOCK_SIZE > MAX_WIDTH)
		vars->width = (MAX_WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
	else
		vars->width = map->width * BLOCK_SIZE;
	if (map->height * BLOCK_SIZE > MAX_HEIGHT - HUD_HEIGHT)
		vars->height = ((MAX_HEIGHT - HUD_HEIGHT) / BLOCK_SIZE) * BLOCK_SIZE;
	else
		vars->height = (map->height * BLOCK_SIZE) + HUD_HEIGHT;
}

static void	init_view_vars(t_view_vars *vars)
{
	vars->b_wall.tab = NULL;
	vars->exit_o.tab = NULL;
	vars->exit_c.tab = NULL;
	vars->floor.tab = NULL;
	vars->img = NULL;
	vars->img_hud_step = NULL;
	vars->img_hud_items = NULL;
	vars->item.tab = NULL;
	vars->l_wall.tab = NULL;
	vars->mlx = NULL;
	vars->player_left.tab = NULL;
	vars->player_right.tab = NULL;
	vars->r_wall.tab = NULL;
	vars->t_wall.tab = NULL;
	vars->f_wall.tab = NULL;
	vars->br_wall.tab = NULL;
	vars->bl_wall.tab = NULL;
	vars->r_br_wall.tab = NULL;
	vars->r_bl_wall.tab = NULL;
}

bool	init_view(t_view_vars *vars, t_map *map)
{
	init_view_vars(vars);
	if (!load_textures(vars))
		return (false);
	set_size(vars, map);
	vars->mlx = mlx_init(vars->width, vars->height, "so_long", false);
	if (!vars->mlx)
		return (false);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	if (!vars->img)
		return (false);
	if (mlx_image_to_window(vars->mlx, vars->img, 0, 0) == -1)
		return (false);
	return (true);
}

void	destroy_view(t_view_vars *vars)
{
	destroy_texture(&(vars->exit_o));
	destroy_texture(&(vars->exit_c));
	destroy_texture(&(vars->floor));
	destroy_texture(&(vars->item));
	destroy_texture(&(vars->player_left));
	destroy_texture(&(vars->player_right));
	destroy_texture(&(vars->t_wall));
	destroy_texture(&(vars->b_wall));
	destroy_texture(&(vars->l_wall));
	destroy_texture(&(vars->r_wall));
	destroy_texture(&(vars->f_wall));
	destroy_texture(&(vars->br_wall));
	destroy_texture(&(vars->bl_wall));
	destroy_texture(&(vars->r_br_wall));
	destroy_texture(&(vars->r_bl_wall));
	if (vars->mlx && vars->img)
		mlx_delete_image(vars->mlx, vars->img);
	if (vars->mlx)
		mlx_terminate(vars->mlx);
}

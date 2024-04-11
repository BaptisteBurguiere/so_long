/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:17:02 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/11 17:15:42 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_move(t_map *map, size_t coord[2])
{
	if (map->player.x == coord[0] && map->player.y == coord[1])
		return ;
	if (!is_wall(map->map[coord[1]][coord[0]]))
	{
		if (map->map[coord[1]][coord[0]] == EXIT && map->nb_items == 0)
			map->is_running = false;
		if (map->map[coord[1]][coord[0]] == ITEM)
		{
			map->nb_items -= 1;
			map->map[coord[1]][coord[0]] = FLOOR;
		}
		map->player.x = coord[0];
		map->player.y = coord[1];
		map->nb_step += 1;
	}
}

void	move(t_map *map, t_move dir, bool *can_move)
{
	size_t	coord[2];

	if (!(*can_move))
		return ;
	coord[0] = map->player.x;
	coord[1] = map->player.y;
	if (dir == up)
		coord[1] -= 1;
	else if (dir == down)
		coord[1] += 1;
	else if (dir == left)
	{
		if (map->player.dir == 'l')
			coord[0] -= 1;
		map->player.dir = 'l';
	}
	else if (dir == right)
	{
		if (map->player.dir == 'r')
			coord[0] += 1;
		map->player.dir = 'r';
	}
	*can_move = false;
	check_move(map, coord);
}

void	manage_move(t_controller *controller)
{
	if (mlx_is_key_down(controller->view->mlx, MLX_KEY_W))
		move(controller->map, up, &(controller->can_move.up));
	else
		controller->can_move.up = true;
	if (mlx_is_key_down(controller->view->mlx, MLX_KEY_S))
		move(controller->map, down, &(controller->can_move.down));
	else
		controller->can_move.down = true;
	if (mlx_is_key_down(controller->view->mlx, MLX_KEY_A))
		move(controller->map, left, &(controller->can_move.left));
	else
		controller->can_move.left = true;
	if (mlx_is_key_down(controller->view->mlx, MLX_KEY_D))
		move(controller->map, right, &(controller->can_move.right));
	else
		controller->can_move.right = true;
}

void	manage_input(void *param)
{
	t_controller	*controller;

	controller = (t_controller *)param;
	if (!controller->map->is_running
		|| mlx_is_key_down(controller->view->mlx, MLX_KEY_ESCAPE))
	{
		destroy_view(controller->view);
		destroy_map(controller->map);
		exit(EXIT_SUCCESS);
	}
	manage_move(controller);
	display_map(controller->view, controller->map);
	display_player(controller->view, controller->map->player);
	display_hud(controller->view, controller->map);
}

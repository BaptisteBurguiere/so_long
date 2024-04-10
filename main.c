/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:24 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/10 14:47:58 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_view_vars	view_vars;

	map = map_parse(argc, argv);
	if (!map)
		exit(EXIT_FAILURE);
	if (!init_view(&view_vars, map))
	{
		destroy_view(&view_vars);
		destroy_map(map);
		exit(EXIT_FAILURE);
	}
	display_map(&view_vars, map);
	display_player(&view_vars, map->player);
	mlx_loop(view_vars.mlx);
	destroy_view(&view_vars);
	destroy_map(map);
}

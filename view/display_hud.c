/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:49:16 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/11 17:38:05 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_frame_x(t_view_vars *vars)
{
	size_t	i;
	size_t	j;

	i = vars->height - HUD_HEIGHT + HUD_PADDING + HUD_BORDER_WIDTH;
	while (i < vars->height - HUD_PADDING - HUD_BORDER_WIDTH)
	{
		j = 0 + HUD_PADDING;
		while (j < HUD_PADDING + HUD_BORDER_WIDTH)
		{
			mlx_put_pixel(vars->img, j, i, HUD_BORDER_COLOR);
			j++;
		}
		i++;
	}
	i = vars->height - HUD_HEIGHT + HUD_PADDING + HUD_BORDER_WIDTH;
	while (i < vars->height - HUD_PADDING - HUD_BORDER_WIDTH)
	{
		j = vars->width - HUD_PADDING - HUD_BORDER_WIDTH;
		while (j < vars->width - HUD_PADDING)
		{
			mlx_put_pixel(vars->img, j, i, HUD_BORDER_COLOR);
			j++;
		}
		i++;
	}
}

void	display_frame_y(t_view_vars *vars)
{
	size_t	i;
	size_t	j;

	i = vars->height - HUD_HEIGHT + HUD_PADDING;
	while (i < vars->height - HUD_HEIGHT + HUD_PADDING + HUD_BORDER_WIDTH)
	{
		j = 0 + HUD_PADDING;
		while (j < vars->width - HUD_PADDING)
		{
			mlx_put_pixel(vars->img, j, i, HUD_BORDER_COLOR);
			j++;
		}
		i++;
	}
	i = vars->height - HUD_PADDING - HUD_BORDER_WIDTH;
	while (i < vars->height - HUD_PADDING)
	{
		j = 0 + HUD_PADDING;
		while (j < vars->width - HUD_PADDING)
		{
			mlx_put_pixel(vars->img, j, i, HUD_BORDER_COLOR);
			j++;
		}
		i++;
	}
}

void	display_bg(t_view_vars *vars)
{
	size_t	i;
	size_t	j;

	i = vars->height - HUD_HEIGHT;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			mlx_put_pixel(vars->img, j, i, HUD_BG_COLOR);
			j++;
		}
		i++;
	}
}

void	display_hud(t_view_vars *vars, t_map *map)
{
	char			*str;
	static size_t	last_step = 1;
	static size_t	last_items = 0;

	display_bg(vars);
	display_frame_y(vars);
	display_frame_x(vars);
	if (last_step != map->nb_step)
	{
		str = ft_itoa((int)(map->nb_step));
		if (vars->img_hud_step != NULL)
			mlx_delete_image(vars->mlx, vars->img_hud_step);
		vars->img_hud_step = mlx_put_string(vars->mlx, str, HUD_PADDING + HUD_BORDER_WIDTH + HUD_PADDING, vars->height - HUD_HEIGHT + HUD_PADDING + HUD_BORDER_WIDTH + HUD_PADDING);
		free(str);
		last_step = map->nb_step;
	}
	if (last_items != map->nb_items)
	{
		str = ft_itoa((int)(map->nb_items));
		if (vars->img_hud_items != NULL)
			mlx_delete_image(vars->mlx, vars->img_hud_items);
		vars->img_hud_items = mlx_put_string(vars->mlx, str, HUD_PADDING + HUD_BORDER_WIDTH + HUD_PADDING, vars->height - HUD_HEIGHT + HUD_PADDING + HUD_BORDER_WIDTH + HUD_PADDING + 20);
		free(str);
		last_items = map->nb_items;
	}
}

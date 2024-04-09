/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburguie <bburguie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:30:19 by bburguie          #+#    #+#             */
/*   Updated: 2024/04/09 18:12:00 by bburguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned long	rgba_to_long(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16)
		+ ((b & 0xff) << 8) + (a & 0xff));
}

void	convert_texture(t_texture *my_texture, mlx_texture_t *mlx_texture)
{
	size_t	i;
	size_t	j;
	size_t	x;

	my_texture->width = mlx_texture->width;
	my_texture->height = mlx_texture->height;
	my_texture->tab = malloc(my_texture->height * sizeof(long *));
	i = 0;
	x = 0;
	while (i < my_texture->height)
	{
		j = 0;
		my_texture->tab[i] = malloc(my_texture->width * sizeof(long));
		while (j < my_texture->width)
		{
			my_texture->tab[i][j] = rgba_to_long(mlx_texture->pixels[x],
					mlx_texture->pixels[x + 1], mlx_texture->pixels[x + 2],
					mlx_texture->pixels[x + 3]);
			j++;
			x += 4;
		}
		i++;
	}
}

bool	load_texture(t_texture *texture, char *path)
{
	mlx_texture_t	*t;

	t = mlx_load_png(path);
	if (!t)
		return (false);
	convert_texture(texture, t);
	mlx_delete_texture(t);
	return (true);
}

bool	load_textures(t_view_vars *vars)
{
	if (!load_texture(&(vars->floor), TEXTURE_FLOOR))
		return (false);
	if (!load_texture(&(vars->t_wall), TEXTURE_TOP_WALL))
		return (false);
	if (!load_texture(&(vars->b_wall), TEXTURE_BOTTOM_WALL))
		return (false);
	if (!load_texture(&(vars->l_wall), TEXTURE_LEFT_WALL))
		return (false);
	if (!load_texture(&(vars->r_wall), TEXTURE_RIGHT_WALL))
		return (false);
	if (!load_texture(&(vars->f_wall), TEXTURE_FULL_WALL))
		return (false);
	if (!load_texture(&(vars->br_wall), TEXTURE_BOTTOM_RIGHT_WALL))
		return (false);
	if (!load_texture(&(vars->bl_wall), TEXTURE_BOTTOM_LEFT_WALL))
		return (false);
	if (!load_texture(&(vars->exit_o), TEXTURE_EXIT_OPEN))
		return (false);
	if (!load_texture(&(vars->exit_c), TEXTURE_EXIT_CLOSE))
		return (false);
	if (!load_texture(&(vars->item), TEXTURE_ITEM))
		return (false);
	if (!load_texture(&(vars->player), TEXTURE_PLAYER))
		return (false);
	return (true);
}

void	destroy_texture(t_texture *texture)
{
	size_t	i;

	if (!texture->tab)
		return ;
	i = 0;
	while (i < texture->height)
	{
		free(texture->tab[i]);
		i++;
	}
	free(texture->tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:19:14 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:26:14 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_win(t_window *mlx, char **map)
{
	mlx->height = height_map(map);
	mlx->width = width_map(map);
	if (mlx->height > MAX_HEIGHT || mlx->width > MAX_WIDTH)
	{
		free(mlx->mp);
		free_map(mlx->map);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		write(1, "Error: map is too big\n", 23);
		exit(1);
	}
	mlx->window = mlx_new_window(mlx->mlx, mlx->width * TILE_SIZE,
			mlx->height * TILE_SIZE, "so_long");
	load_images(mlx);
	draw_map(mlx, map);
}

void	load_images(t_window *mlx)
{
	int	a;
	int	b;

	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "text/idle_00.xpm", &a, &b);
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, "text/wall.xpm", &a, &b);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "text/portal.xpm", &a, &b);
	mlx->collectibles = mlx_xpm_file_to_image(mlx->mlx, "text/coins.xpm",
			&a, &b);
	if (!mlx->player || !mlx->collectibles || !mlx->exit || !mlx->bg)
	{
		free(mlx->mp);
		free_map(mlx->map);
		clear_imag(mlx);
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	draw_map(t_window *mlx, char **map)
{
	int (pos_x), (pos_y);
	pos_x = 0;
	while (map[pos_x])
	{
		pos_y = 0;
		while (map[pos_x][pos_y])
		{
			if (map[pos_x][pos_y] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->bg, pos_y
					* 32, pos_x * 32);
			else if (map[pos_x][pos_y] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->player,
					pos_y * 32, pos_x * 32);
			else if (map[pos_x][pos_y] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->collectibles, pos_y * 32, pos_x * 32);
			else if (map[pos_x][pos_y] == 'E')
			{
				mlx->mp->pos_x_e = pos_x;
				mlx->mp->pos_y_e = pos_y;
			}
			pos_y++;
		}
		pos_x++;
	}
}

int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width_map(char **map)
{
	t_window	wi;

	wi.width = ft_strlen(map[0]) - 1;
	return (wi.width);
}

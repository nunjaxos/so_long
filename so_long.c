/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:55 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/14 23:29:36 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	key_press(int keycode, t_window *mlx)
{
	if (keycode == ESC)
		clear_win(mlx);
	if (keycode == D)
		mov_right(mlx);
	else if (keycode == W)
		mov_up(mlx);
	else if (keycode == A)
		mov_left(mlx);
	else if (keycode == S)
		mov_down(mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	if (mlx->mp->c == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->exit,
			mlx->mp->pos_y_e * 32, mlx->mp->pos_x_e * 32);
		mlx->map[mlx->mp->pos_x_e][mlx->mp->pos_y_e] = 'E';
	}
	draw_map(mlx, mlx->map);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	mlx;

	ft_bzero(&mlx, sizeof(t_window));
	mlx.mp = malloc(sizeof(t_map));
	if (!mlx.mp)
		return (1);
	ft_bzero(mlx.mp, sizeof(t_map));
	if (ac != 2)
	{
		write(1, "Error\n", 6);
		write(1, "Give me file", 13);
		free(mlx.mp);
		exit(1);
	}
	parsi_map(av[1], &mlx, mlx.mp);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		perror("Allocation");
		return (2);
	}
	new_win(&mlx, mlx.map);
	mlx_hook(mlx.window, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.window, 17, 0, sed, &mlx);
	mlx_loop(mlx.mlx);
}

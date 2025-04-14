/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:45 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/14 23:22:46 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_win(t_window *mlx)
{
	free_map(mlx->map);
	free(mlx->mp);
	clear_imag(mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	sed(t_window *mlx)
{
	clear_win(mlx);
	return (0);
}

void	clear_imag(t_window *mlx)
{
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->bg)
		mlx_destroy_image(mlx->mlx, mlx->bg);
	if (mlx->collectibles)
		mlx_destroy_image(mlx->mlx, mlx->collectibles);
	if (mlx->exit)
		mlx_destroy_image(mlx->mlx, mlx->exit);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	exit_map(char **map)
{
	write(1, "Error\n", 6);
	write(1, "map invalid\n", 13);
	free_map(map);
	exit(1);
}

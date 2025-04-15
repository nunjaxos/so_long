/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:55 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:22:27 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nl(t_window *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = mlx->map_len;
	while (i < j)
	{
		if (mlx->map[i][0] == '\n')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
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
	parsing(av[1], &mlx, mlx.mp);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		perror("Allocation");
		return (1);
	}
	new_win(&mlx, mlx.map);
	mlx_hook(mlx.window, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.window, 17, 0, sed, &mlx);
	mlx_loop(mlx.mlx);
}

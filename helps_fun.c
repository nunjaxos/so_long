/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:27 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/14 23:22:28 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	load_images(t_window *mlx)
{
	int	a;
	int	b;

	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "textures/pac.xpm", &a, &b);
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, "textures/wall.xpm", &a, &b);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "textures/portal.xpm", &a, &b);
	mlx->collectibles = mlx_xpm_file_to_image(mlx->mlx, "textures/coins.xpm",
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

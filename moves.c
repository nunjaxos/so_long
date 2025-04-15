/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:23 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:23:23 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	mov_down(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] != '1')
	{
		if (mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_y++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\n", 1);
	}
}

void	mov_left(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] != '1')
	{
		if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_x--;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\n", 1);
	}
}

void	mov_right(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] != '1')
	{
		if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_x++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\n", 1);
	}
}

void	mov_up(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] != '1')
	{
		if (mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_y--;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\n", 1);
	}
}

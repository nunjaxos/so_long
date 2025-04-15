/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:02 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:29:46 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		mod;

	mod = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n / mod >= 10)
		mod *= 10;
	while (mod > 0)
	{
		c = (n / mod) + 48;
		write(fd, &c, 1);
		n %= mod;
		mod /= 10;
	}
}

void	check_element(char **map, t_map *mp)
{
	while (map[mp->i])
	{
		mp->j = 0;
		while (map[mp->i][mp->j])
		{
			if (map[mp->i][mp->j] == 'C')
				mp->c++;
			else if (map[mp->i][mp->j] == 'P')
			{
				mp->pos_y = mp->i;
				mp->pos_x = mp->j;
				mp->p++;
			}
			else if (map[mp->i][mp->j] == 'E')
				mp->e++;
			mp->j++;
		}
		mp->i++;
	}
	if (mp->c < 1 || mp->e != 1 || mp->p != 1)
	{
		free(mp);
		exit_map(map);
	}
}

int	len_frst_line(char **map, t_map *mp)
{
	int (i), (j), (k);
	k = 1;
	i = ft_strlen(map[0]);
	if (i == 0)
	{
		free(mp);
		exit_map(map);
	}
	if (map[0][i - 1] == '\n')
		i--;
	while (map[k])
	{
		j = ft_strlen(map[k]);
		if (map[k][j - 1] == '\n')
			j--;
		if (j != i)
			return (1);
		k++;
	}
	return (0);
}

void	error_fd(void)
{
	write(1, "Error\n", 6);
	write(1, "map files error !", 18);
	exit(1);
}

void	parsing(char *path_file, t_window *mlx, t_map *mp)
{
	int		fd;
	char	**a;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
	{
		free(mp);
		error_fd();
	}
	check_dot_ber(path_file, mp);
	mlx->map_len = len_map(path_file);
	mlx->map = get_map(path_file, mlx->map_len, mp);
	check_word(mlx->map, mp);
	check_word_two(mlx->map, path_file, mp);
	check_nonvalid(mlx->map, mp);
	check_element(mlx->map, mp);
	a = map_copy(mlx->map, path_file);
	flood_fill(mp->pos_x, mp->pos_y, a);
	check_element_validity(a, mp, mlx->map);
	close(fd);
	free_map(a);
}

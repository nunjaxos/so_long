/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:37 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:23:00 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_element_copy(char **map, t_map *mp)
{
	int (c), (e), (p);
	mp->i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (map[mp->i])
	{
		mp->j = 0;
		while (map[mp->i][mp->j])
		{
			if (map[mp->i][mp->j] == 'C')
				c++;
			else if (map[mp->i][mp->j] == 'P')
				p++;
			else if (map[mp->i][mp->j] == 'E')
				e++;
			mp->j++;
		}
		mp->i++;
	}
	if (c != 0 || e != 0 || p != 0)
		return (1);
	return (0);
}

char	**map_copy(char **map, char *path_file)
{
	int		i;
	int		len;
	char	**copy_map;

	i = 0;
	len = len_map(path_file);
	copy_map = malloc(sizeof(char *) * (len + 1));
	if (!copy_map)
	{
		free_map(map);
		return (NULL);
	}
	while (i < len)
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	flood_fill(int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'Q')
		return ;
	map[y][x] = 'Q';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}

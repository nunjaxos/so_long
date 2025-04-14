/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:16 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/14 23:22:17 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(char *path_file)
{
	int		fd;
	int		len;
	char	*r_l_map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = 0;
	r_l_map = get_next_line(fd);
	while (r_l_map && r_l_map[0] == '1')
	{
		len++;
		free(r_l_map);
		r_l_map = get_next_line(fd);
	}
	free(r_l_map);
	return (len);
}

void	loop_map(char *r_l_line, int fd, char **map, t_map *mp)
{
	while (r_l_line)
	{
		if (r_l_line[0] != '\n')
		{
			free(r_l_line);
			free(mp);
			exit_map(map);
		}
		free(r_l_line);
		r_l_line = get_next_line(fd);
	}
}

char	**get_map(char *path_file, int len, t_map *mp)
{
	int		fd;
	int		i;
	char	*r_l_line;
	char	**map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	r_l_line = get_next_line(fd);
	loop_map(r_l_line, fd, map, mp);
	close(fd);
	return (map);
}

void	check_dot_ber(char *path_file, t_map *mp)
{
	int	i;

	i = 0;
	while (path_file[i])
	{
		if (path_file[i] == '/' || ft_strlen(path_file) <= 4)
		{
			if (ft_strlen(&path_file[i + 1]) <= 4
				|| ft_strlen(path_file) <= 4)
			{
				free(mp);
				write(1, "Error\n", 6);
				write(1, "Only valid \".ber\" map files are allowed!\n", 42);
				exit(1);
			}
		}
		i++;
	}
	if (ft_strncmp(path_file + ft_strlen(path_file) - 4, ".ber", 4))
	{
		free(mp);
		write(1, "Error\n", 6);
		write(1, "Only valid \".ber\" map files are allowed!\n", 42);
		exit(1);
	}
}

void	check_nonvalid(char **map, t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
			{
				free(mp);
				exit_map(map);
			}
			j++;
		}
		i++;
	}
}

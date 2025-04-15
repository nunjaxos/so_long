/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:08 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 07:45:53 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	free_exit(char **map, t_map *mp)
{
	free(mp);
	exit_map(map);
}

void	check_word(char **map, t_map *mp)
{
	int (len_line), (len), (len_m), (i);
	len_line = ft_strlen(map[0]) - 1;
	if (len_line <= 0)
		free_exit(map, mp);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len -= 1;
		if (len_line != len)
			free_exit(map, mp);
		i++;
	}
	len_m = i;
	i = 0;
	while (i < len_m)
	{
		if (map[i][len_line - 1] != '1' || map[i][0] != '1')
			free_exit(map, mp);
		i++;
	}
}

void	check_word_two(char **map, char *path_file, t_map *mp)
{
	int (i), (j), (len);
	i = 0;
	j = 0;
	len = len_map(path_file);
	if (len == 0)
		free_exit(map, mp);
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			free_exit(map, mp);
		j++;
	}
	j = 0;
	while (map[len - 1][j])
	{
		if (map[len - 1][j] != '1' && map[len - 1][j] != '\n')
			free_exit(map, mp);
		j++;
	}
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] != '\0')
			{
				if (to_find[j] != str[i])
					break ;
				i++;
				j++;
			}
			if (to_find[j] == '\0')
				return (1);
		}
		else
			i++;
	}
	return (0);
}

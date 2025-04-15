/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:48 by abhmidat          #+#    #+#             */
/*   Updated: 2025/04/15 08:08:27 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		pos_x;
	int		pos_y;
	int		pos_x_e;
	int		pos_y_e;
}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	char	*left;
	char	*right;
	char	*up;
	char	*down;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		map_len;
	void	*collectibles;
	int		x;
	int		y;
	void	*player;
	void	*exit;
	void	*bg;
	t_map	*mp;
}			t_window;

		//keys
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define CLOSE 17
# define MAX_HEIGHT 540
# define MAX_WIDTH 960
# define TILE_SIZE 32

			//parsing
void		parsing(char *path_file, t_window *mlx, t_map *mp);
void		check_nl(t_window *mlx);
int			len_map(char *path_file);
char		**get_map(char *path_file, int len, t_map *mp);
int			len_frst_line(char **map, t_map *mp);
void		check_dot_ber(char *path_file, t_map *mp);
void		check_nonvalid(char **map, t_map *mp);
char		**map_copy(char **map, char *path_file);
void		flood_fill(int x, int y, char **map);
int			check_element_copy(char **map, t_map *mp);
void		check_word(char **map, t_map *mp);
void		check_word_two(char **map, char *path_file, t_map *mp);
//			clean_functions
void		clear_imag(t_window *mlx);
void		free_exit(char **map, t_map *mp);
void		exit_map(char **map);
void		free_map(char **map);
void		clear_win(t_window *mlx);
int			sed(t_window *mlx);
			//display
void		new_win(t_window *mlx, char **map);
int			height_map(char **map);
int			width_map(char **map);
void		load_images(t_window *mlx);
void		new_win(t_window *mlx, char **map);
void		draw_map(t_window *mlx, char **map);
			//moves
void		mov_left(t_window *mlx);
void		mov_right(t_window *mlx);
void		mov_up(t_window *mlx);
void		mov_down(t_window *mlx);
			//helper_functions
void		check_element_validity(char **a, t_map *mp, char **map);
void		ft_bzero(void *s, size_t n);
char		*get_next_line(int fd);			
int			ft_strstr(char *str, char *to_find);			
char		*ft_strdup(const char *s);			
int			ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
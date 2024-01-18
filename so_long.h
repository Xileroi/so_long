/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:48:10 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/18 15:15:50 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define TILE 32

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_sprites{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
}t_sprites;

typedef struct s_design{
	int	player;
	int	end;
	int	coin;
	int	vilain;
}t_design;

typedef struct s_location{
	int	x;
	int	y;
}t_location;

typedef struct s_cord{
	int	x;
	int	y;
}t_cord;

typedef struct s_cord_v{
	int	x;
	int	y;
}t_cord_v;

typedef struct s_outline
{
	int		lenght;
	int		height;
	char	**map;
}t_outline;

typedef struct s_depend
{
	int	coins;
	int	exit;
	int	player;
}t_depend;

typedef struct s_position{
	t_cord		p_player;
	int			p_end;
	int			p_coin;
}t_position;

typedef struct s_var{
	int	i;
	int	j;
	int	v_i;
	int	v_j;
	int	d_x;
	int	d_y;
}t_var;

typedef struct s_game
{
	t_depend	cep;
	t_outline	map;
	void		*mlx;
	void		*win;
	int			steps;
	t_sprites	img;
	t_var		var;
	t_location	loc;
	t_position	pos;
	int			end_game;
	int			key;
	int			x;
	int			y;
}t_game;

char	*get_backup(char *str);
char	*gnl_getline(char *str);
char	*gnl_newfile(int fd, char *save);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_check_first(char *str, t_game *all);
int		ft_check_dependances(char *str, t_game *all);
char	**map_read(int fd, t_game *all);
int		ft_check_last(char *str, int i, int save);
int		ft_check_name(char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_check_btw(char *str, int i, int save, t_game *all);
int		finito(int i);

void	colle_image_ground(t_game *all);
int		ini_so_long(int fd, t_game *all);
void	wasd(t_game *all);
void	ft_graphic(t_game *all);
int		ft_refresh(t_game *all);
void	ft_ini_sprites(t_game *all);
void	ini_variable(t_game *all);
void	backslash_n(t_game *all);
void	ini_mlx(t_game *all);
void	free_map(t_game *all);
int		kill_window(t_game *all);
void	colle_image_coin(t_game *all);
void	colle_image_player(t_game *all);
void	colle_image_exit(t_game *all);
void	colle_image_wall(t_game *all);
void	kill_player(t_game *all);
void	put_steps(t_game *all);
int		ft_check_wall(t_game *all, int col, int line);
void	ft_update(int col, int line, t_game *all);
int		deplacement(int keycode, t_game *all);
int		ft_nlen(int c);
char	*ft_itoa(int n);
int	ft_parse_map(char **map);

#endif
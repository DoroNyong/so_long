/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:54:22 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:48 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define KEY_ESC	65307
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define I_SIZE	16

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_tmp
{
	int	x;
	int	y;
}	t_tmp;

typedef struct s_map_size
{
	int	x;
	int	y;
}	t_map_size;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_sl
{
	t_data		data;
	t_tmp		tmp;
	t_map_size	map_size;
	t_player	player;
	int			i_wid;
	int			i_hei;
	void		*i_1;
	void		*i_0;
	void		*i_p;
	void		*i_c;
	void		*i_e;
	char		**map;
	int			collection;
	int			move_num;
	int			is_gameover;
}	t_sl;

typedef struct s_check
{
	int		x;
	int		y;
	int		c_count;
	int		e_reached;
	char	**map_cpy;
}	t_check;

int		key_press(int keycode, t_sl *sl);
int		mouse_press(int button, int x, int y, void *p);
int		close_window(t_sl *sl);
char	*make_map_str(char *map_name);
void	free_all(char **res, int index);
char	**map_check(t_sl *sl, char *map_name);
char	**map_check_1(t_sl *sl, char *map_name);
void	map_check_2(t_sl *sl, char **map);
void	map_check_3(t_sl *sl, char **map);
char	**map_copy_arr(t_sl *sl, char **map);
void	map_copy(t_sl *sl, char **map_cpy, char **map);
void	exit_with_error(char *message);
void	draw_map(t_sl *sl);
void	player_move_w(t_sl *sl);
void	player_move_a(t_sl *sl);
void	player_move_s(t_sl *sl);
void	player_move_d(t_sl *sl);

#endif
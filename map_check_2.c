/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:26 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:51 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_sl *sl, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < sl->map_size.y)
	{
		x = 0;
		if (y == 0 || y == (sl->map_size.y - 1))
		{
			while (map[y][x])
			{
				if (map[y][x] != '1')
					return (1);
				x++;
			}
		}
		else
		{
			if (map[y][0] != '1' || map[y][sl->map_size.x - 1] != '1')
				return (1);
		}
		y++;
	}
	return (0);
}

int	check_element(t_sl *sl, char c, int *p, int *e)
{
	if (c == 'C')
		sl->collection++;
	else if (c == 'P')
	{
		if (*p)
			return (3);
		*p = 1;
	}
	else if (c == 'E')
	{
		if (*e)
			return (4);
		*e = 1;
	}
	return (0);
}

int	check_char(t_sl *sl, char **map)
{
	int	y;
	int	x;
	int	p;
	int	e;
	int	error_num;

	y = -1;
	p = 0;
	e = 0;
	sl->collection = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' \
				&& map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E')
				return (2);
			error_num = check_element(sl, map[y][x], &p, &e);
			if (error_num)
				return (error_num);
		}
	}
	return (!(sl->collection && p && e));
}

void	map_check_2(t_sl *sl, char **map)
{
	int	error_num;

	if (check_wall(sl, map))
	{
		free_all(map, sl->map_size.y);
		exit_with_error("Map is not walled");
	}
	error_num = check_char(sl, map);
	if (error_num)
	{
		free_all(map, sl->map_size.y);
		if (error_num == 1)
			exit_with_error("Map is missing required components");
		else if (error_num == 2)
			exit_with_error("Map contains unspecified characters");
		else if (error_num == 3)
			exit_with_error("Map has more than one P");
		else if (error_num == 4)
			exit_with_error("Map has more than one E");
	}
}

void	map_copy(t_sl *sl, char **map_cpy, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < sl->map_size.y)
	{
		x = -1;
		while (++x < sl->map_size.x)
		{
			map_cpy[y][x] = map[y][x];
		}
	}
}

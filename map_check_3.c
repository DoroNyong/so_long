/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:42:56 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:51 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_start_pos(t_sl *sl, char **map, t_check *check)
{
	check->c_count = 0;
	check->e_reached = 0;
	check->map_cpy = map_copy_arr(sl, map);
	if (!check->map_cpy)
	{
		free_all(map, sl->map_size.y);
		exit(1);
	}
	map_copy(sl, check->map_cpy, map);
	sl->tmp.y = -1;
	while (map[++(sl->tmp.y)])
	{
		sl->tmp.x = -1;
		while (map[sl->tmp.y][++(sl->tmp.x)])
		{
			if (map[sl->tmp.y][sl->tmp.x] == 'P')
			{
				check->x = sl->tmp.x;
				check->y = sl->tmp.y;
				break ;
			}
		}
	}
}

void	map_bt_c(char **map, int x, int y, int *c_count)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		(*c_count)++;
	map[y][x] = 'V';
	map_bt_c(map, x + 1, y, c_count);
	map_bt_c(map, x - 1, y, c_count);
	map_bt_c(map, x, y + 1, c_count);
	map_bt_c(map, x, y - 1, c_count);
}

void	map_bt_e(char **map, int x, int y, int *e_reached)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		(*e_reached) = 1;
		return ;
	}
	map[y][x] = 'V';
	map_bt_e(map, x + 1, y, e_reached);
	map_bt_e(map, x - 1, y, e_reached);
	map_bt_e(map, x, y + 1, e_reached);
	map_bt_e(map, x, y - 1, e_reached);
}

void	map_check_3(t_sl *sl, char **map)
{
	t_check	check;

	set_start_pos(sl, map, &check);
	map_bt_c(check.map_cpy, check.x, check.y, &(check.c_count));
	if (check.c_count != sl->collection)
	{
		free_all(map, sl->map_size.y);
		free_all(check.map_cpy, sl->map_size.y);
		exit_with_error("Not all collections are reachable");
	}
	map_copy(sl, check.map_cpy, map);
	map_bt_e(check.map_cpy, check.x, check.y, &(check.e_reached));
	free_all(check.map_cpy, sl->map_size.y);
	if (!(check.e_reached))
	{
		free_all(map, sl->map_size.y);
		exit_with_error("Exit blocked after collection");
	}
}

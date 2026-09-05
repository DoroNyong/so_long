/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:14:56 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:50 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_w(t_sl *sl)
{
	if (sl->map[sl->player.y - 1][sl->player.x] == '1')
		return ;
	else if (sl->map[sl->player.y - 1][sl->player.x] == 'E')
	{
		if (sl->collection == 0)
			sl->is_gameover = 1;
		else
			return ;
	}
	else if (sl->map[sl->player.y - 1][sl->player.x] == 'C')
	{
		sl->map[sl->player.y - 1][sl->player.x] = '0';
		sl->collection--;
	}
	sl->map[sl->player.y][sl->player.x] = '0';
	sl->map[sl->player.y - 1][sl->player.x] = 'P';
	sl->player.y--;
	sl->move_num++;
	ft_printf("이동 횟수 : %d\n", sl->move_num);
	draw_map(sl);
}

void	player_move_a(t_sl *sl)
{
	if (sl->map[sl->player.y][sl->player.x - 1] == '1')
		return ;
	else if (sl->map[sl->player.y][sl->player.x - 1] == 'E')
	{
		if (sl->collection == 0)
			sl->is_gameover = 1;
		else
			return ;
	}
	else if (sl->map[sl->player.y][sl->player.x - 1] == 'C')
	{
		sl->map[sl->player.y][sl->player.x - 1] = '0';
		sl->collection--;
	}
	sl->map[sl->player.y][sl->player.x] = '0';
	sl->map[sl->player.y][sl->player.x - 1] = 'P';
	sl->player.x--;
	sl->move_num++;
	ft_printf("이동 횟수 : %d\n", sl->move_num);
	draw_map(sl);
}

void	player_move_s(t_sl *sl)
{
	if (sl->map[sl->player.y + 1][sl->player.x] == '1')
		return ;
	else if (sl->map[sl->player.y + 1][sl->player.x] == 'E')
	{
		if (sl->collection == 0)
			sl->is_gameover = 1;
		else
			return ;
	}
	else if (sl->map[sl->player.y + 1][sl->player.x] == 'C')
	{
		sl->map[sl->player.y + 1][sl->player.x] = '0';
		sl->collection--;
	}
	sl->map[sl->player.y][sl->player.x] = '0';
	sl->map[sl->player.y + 1][sl->player.x] = 'P';
	sl->player.y++;
	sl->move_num++;
	ft_printf("이동 횟수 : %d\n", sl->move_num);
	draw_map(sl);
}

void	player_move_d(t_sl *sl)
{
	if (sl->map[sl->player.y][sl->player.x + 1] == '1')
		return ;
	else if (sl->map[sl->player.y][sl->player.x + 1] == 'E')
	{
		if (sl->collection == 0)
			sl->is_gameover = 1;
		else
			return ;
	}
	else if (sl->map[sl->player.y][sl->player.x + 1] == 'C')
	{
		sl->map[sl->player.y][sl->player.x + 1] = '0';
		sl->collection--;
	}
	sl->map[sl->player.y][sl->player.x] = '0';
	sl->map[sl->player.y][sl->player.x + 1] = 'P';
	sl->player.x++;
	sl->move_num++;
	ft_printf("이동 횟수 : %d\n", sl->move_num);
	draw_map(sl);
}

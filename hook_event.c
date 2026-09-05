/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:16:23 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:52 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_sl *sl)
{
	if (keycode == KEY_W)
		player_move_w(sl);
	else if (keycode == KEY_S)
		player_move_s(sl);
	else if (keycode == KEY_A)
		player_move_a(sl);
	else if (keycode == KEY_D)
		player_move_d(sl);
	else if (keycode == KEY_ESC)
		close_window(sl);
	else
		return (0);
	if (sl->is_gameover)
	{
		ft_printf("게임 끝!\n");
		close_window(sl);
	}
	return (0);
}

int	close_window(t_sl *sl)
{
	mlx_destroy_image(sl->data.mlx, sl->i_1);
	mlx_destroy_image(sl->data.mlx, sl->i_0);
	mlx_destroy_image(sl->data.mlx, sl->i_p);
	mlx_destroy_image(sl->data.mlx, sl->i_e);
	mlx_destroy_image(sl->data.mlx, sl->i_c);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	free_all(sl->map, sl->map_size.y);
	exit(0);
	return (0);
}

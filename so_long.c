/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:02:04 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:49 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_sl *sl)
{
	sl->tmp.y = -1;
	while (sl->map[++(sl->tmp.y)])
	{
		sl->tmp.x = -1;
		while (sl->map[sl->tmp.y][++(sl->tmp.x)])
		{
			if (sl->map[sl->tmp.y][sl->tmp.x] == 'P')
			{
				sl->player.x = sl->tmp.x;
				sl->player.y = sl->tmp.y;
				return ;
			}
		}
	}
}

void	sl_init(t_sl *sl)
{
	sl->data.mlx = mlx_init();
	sl->data.win = mlx_new_window(sl->data.mlx, I_SIZE * sl->map_size.x \
			, I_SIZE * sl->map_size.y, "new");
	sl->i_1 = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/tree.xpm", &(sl->i_wid), &(sl->i_hei));
	sl->i_0 = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/ground.xpm", &(sl->i_wid), &(sl->i_hei));
	sl->i_c = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/chest.xpm", &(sl->i_wid), &(sl->i_hei));
	sl->i_e = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/house.xpm", &(sl->i_wid), &(sl->i_hei));
	sl->i_p = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/player.xpm", &(sl->i_wid), &(sl->i_hei));
	player_init(sl);
	sl->is_gameover = 0;
	sl->move_num = 0;
}

void	draw_map(t_sl *sl)
{
	sl->tmp.y = -1;
	while (sl->map[++(sl->tmp.y)])
	{
		sl->tmp.x = -1;
		while (sl->map[sl->tmp.y][++(sl->tmp.x)])
		{
			if (sl->map[sl->tmp.y][sl->tmp.x] == '1')
				mlx_put_image_to_window(sl->data.mlx, sl->data.win \
					, sl->i_1, sl->tmp.x * I_SIZE, sl->tmp.y * I_SIZE);
			else if (sl->map[sl->tmp.y][sl->tmp.x] == 'P')
				mlx_put_image_to_window(sl->data.mlx, sl->data.win \
					, sl->i_p, sl->tmp.x * I_SIZE, sl->tmp.y * I_SIZE);
			else if (sl->map[sl->tmp.y][sl->tmp.x] == 'C')
				mlx_put_image_to_window(sl->data.mlx, sl->data.win \
					, sl->i_c, sl->tmp.x * I_SIZE, sl->tmp.y * I_SIZE);
			else if (sl->map[sl->tmp.y][sl->tmp.x] == 'E')
				mlx_put_image_to_window(sl->data.mlx, sl->data.win \
					, sl->i_e, sl->tmp.x * I_SIZE, sl->tmp.y * I_SIZE);
			else
				mlx_put_image_to_window(sl->data.mlx, sl->data.win \
					, sl->i_0, sl->tmp.x * I_SIZE, sl->tmp.y * I_SIZE);
		}
	}
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("Error\n반드시 하나의 맵을 사용해야 합니다.\n");
		return (0);
	}
	sl.map = map_check(&sl, argv[1]);
	sl_init(&sl);
	draw_map(&sl);
	mlx_key_hook(sl.data.win, &key_press, &sl);
	mlx_hook(sl.data.win, 17, 0, &close_window, &sl);
	mlx_loop(sl.data.mlx);
	return (0);
}

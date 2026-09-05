/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:31:40 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:50 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **res, int index)
{
	while (--index >= 0)
		free(res[index]);
	free(res);
}

int	check_map_name(char *map_name)
{
	int	len;

	len = 0;
	while (map_name[len])
		len++;
	if (!(map_name[len - 1] == 'r' && map_name[len - 2] == 'e' \
		&& map_name[len - 3] == 'b' && map_name[len - 4] == '.'))
		return (1);
	if (!((map_name[len - 5] >= 'a' && map_name[len - 5] <= 'z') \
		|| (map_name[len - 5] >= 'A' && map_name[len - 5] <= 'Z') \
		|| (map_name[len - 5] >= '0' && map_name[len - 5] <= '9')))
		return (1);
	return (0);
}

void	exit_with_error(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

char	**map_check(t_sl *sl, char *map_name)
{
	char	**map;

	if (check_map_name(map_name))
		exit_with_error("Map name must end with .ber");
	map = map_check_1(sl, map_name);
	if (!map)
		exit(1);
	map_check_2(sl, map);
	map_check_3(sl, map);
	return (map);
}

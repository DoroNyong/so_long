/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:39:00 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:51 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(t_sl *sl, char *map_str)
{
	int	x;

	if (!map_str || *map_str == '\0' || map_str[0] == '\n')
		return (1);
	x = 0;
	sl->map_size.x = -1;
	sl->map_size.y = 1;
	while (*map_str)
	{
		if (*map_str == '\n')
		{
			if (x == 0 || *(map_str + 1) == '\0')
				return (1);
			if (sl->map_size.x == -1)
				sl->map_size.x = x;
			else if (sl->map_size.x != x)
				return (1);
			x = 0;
			sl->map_size.y++;
		}
		else
			x++;
		map_str++;
	}
	return (sl->map_size.x != x);
}

void	arr_put_map(char ***map, char *map_str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (*map_str)
	{
		if (*map_str == '\n')
		{
			(*map)[y][x] = '\0';
			x = 0;
			y++;
		}
		else
			(*map)[y][x++] = *map_str;
		map_str++;
	}
	(*map)[y][x] = '\0';
}

char	**make_map_arr(t_sl *sl, char *map_str)
{
	char	**res;
	int		index;

	res = (char **)malloc(sizeof(char *) * (sl->map_size.y + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < sl->map_size.y)
	{
		res[index] = (char *)malloc(sizeof(char) * (sl->map_size.x + 1));
		if (!res[index])
		{
			free_all(res, index);
			return (NULL);
		}
		index++;
	}
	res[index] = NULL;
	arr_put_map(&res, map_str);
	return (res);
}

char	**map_check_1(t_sl *sl, char *map_name)
{
	char	*map_str;
	char	**map;

	map_str = NULL;
	map_str = make_map_str(map_name);
	if (!map_str)
		return (NULL);
	if (check_rect(sl, map_str))
	{
		free(map_str);
		exit_with_error("Map must be rectangular");
	}
	map = make_map_arr(sl, map_str);
	free(map_str);
	if (!map)
		return (NULL);
	return (map);
}

char	**map_copy_arr(t_sl *sl, char **map)
{
	char	**res;
	int		index;

	res = (char **)malloc(sizeof(char *) * (sl->map_size.y + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < sl->map_size.y)
	{
		res[index] = (char *)malloc(sizeof(char) * (sl->map_size.x + 1));
		if (!res[index])
		{
			free_all(res, index);
			return (NULL);
		}
		ft_strlcpy(res[index], map[index], ft_strlen(map[index]));
		index++;
	}
	res[index] = NULL;
	return (res);
}

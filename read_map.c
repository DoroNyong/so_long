/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:39:53 by hjang             #+#    #+#             */
/*   Updated: 2025/03/17 04:50:49 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	num;

	if (!s)
		return (0);
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*tmp;
	size_t	index;
	size_t	index2;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (NULL);
	index = -1;
	while (++index < s1_len)
		tmp[index] = s1[index];
	index2 = 0;
	while (index2 < s2_len)
		tmp[index++] = s2[index2++];
	tmp[index] = '\0';
	free(s1);
	return (tmp);
}

char	*read_map(int fd)
{
	char	buf[11];
	char	*res;
	int		read_num;

	res = (char *)malloc(sizeof(char) * 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	while (1)
	{
		read_num = read(fd, buf, 10);
		if (read_num < 0)
		{
			if (res)
				free(res);
			return (NULL);
		}
		else if (read_num == 0)
			break ;
		buf[read_num] = '\0';
		res = ft_strjoin(res, buf);
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*make_map_str(char *map_name)
{
	char	*res;
	int		fd;

	fd = open(map_name, O_RDONLY);
	res = read_map(fd);
	if (!res)
		exit_with_error("Map read failed");
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:43 by hjang             #+#    #+#             */
/*   Updated: 2024/12/26 14:36:40 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_s(char *s, size_t len)
{
	size_t	num_div;
	size_t	count;

	num_div = (size_t)INT_MAX / 2;
	count = len / num_div;
	while (count-- > 0)
	{
		write(1, s, num_div);
		s += num_div;
		len -= num_div;
	}
	write(1, s, len);
}

int	word_s(va_list args)
{
	int		count;
	char	*s;
	char	*tmp;
	size_t	len;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		count += (int)write(1, "(null)", 6);
		return (count);
	}
	tmp = s;
	len = 0;
	while (*(tmp++) != '\0')
		len++;
	write_s(s, len);
	if (len > (size_t)INT_MAX)
		count = -1;
	else
		count += (int)len;
	return (count);
}

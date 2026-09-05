/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:56 by hjang             #+#    #+#             */
/*   Updated: 2024/11/04 17:11:49 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	num;

	if (size == 0)
		return (ft_strlen(src));
	num = 0;
	while ((num + 1) < size && src[num] != '\0')
	{
		dst[num] = src[num];
		num++;
	}
	dst[num] = '\0';
	return (ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:53:47 by hjang             #+#    #+#             */
/*   Updated: 2024/11/04 17:11:49 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	s_len;

	s_len = ft_strlen(s);
	tmp = malloc(sizeof(char) * (s_len + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, s_len + 1);
	return (tmp);
}

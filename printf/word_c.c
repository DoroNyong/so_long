/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:17:33 by hjang             #+#    #+#             */
/*   Updated: 2024/12/13 15:21:25 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	word_c(va_list args)
{
	int		count;
	char	c;

	count = 0;
	c = (char)va_arg(args, int);
	count = (int)write(1, &c, 1);
	return (count);
}

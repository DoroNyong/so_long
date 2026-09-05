/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:13:43 by hjang             #+#    #+#             */
/*   Updated: 2024/12/13 14:42:59 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_u(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		putnbr_u(n / 10, count);
	c = (char)((n % 10) + '0');
	*count += (int)write(1, &c, 1);
}

int	word_u(va_list args)
{
	int				count;
	unsigned int	u;

	count = 0;
	u = va_arg(args, unsigned int);
	putnbr_u(u, &count);
	return (count);
}

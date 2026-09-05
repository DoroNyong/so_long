/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:12:51 by hjang             #+#    #+#             */
/*   Updated: 2025/03/13 17:53:12 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		*count = (int)write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		*count += (int)write(1, "-", 1);
	}
	if (n >= 10)
		putnbr(n / 10, count);
	c = (char)((n % 10) + '0');
	*count += (int)write(1, &c, 1);
}

int	word_d(va_list args)
{
	int	count;
	int	d;

	count = 0;
	d = va_arg(args, int);
	putnbr(d, &count);
	return (count);
}

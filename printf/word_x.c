/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:00 by hjang             #+#    #+#             */
/*   Updated: 2025/03/13 17:53:24 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_x(unsigned int n, char *x_binary, int *count)
{
	if (n >= 16)
		putnbr_x(n / 16, x_binary, count);
	*count += (int)write(1, &x_binary[(n % 16)], 1);
}

int	word_x(char c, va_list args)
{
	int				count;
	unsigned int	x;
	char			*x_binary;

	count = 0;
	x = va_arg(args, unsigned int);
	if (c == 'x')
		x_binary = "0123456789abcdef";
	else
		x_binary = "0123456789ABCDEF";
	putnbr_x(x, x_binary, &count);
	return (count);
}

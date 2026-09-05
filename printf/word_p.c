/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:01:53 by hjang             #+#    #+#             */
/*   Updated: 2025/03/13 17:53:30 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_p(unsigned long n, char *x_binary, int *count)
{
	if (n >= 16)
		putnbr_p(n / 16, x_binary, count);
	*count += (int)write(1, &x_binary[(n % 16)], 1);
}

int	word_p(va_list args)
{
	int		count;
	void	*p;
	char	*x_binary;

	count = 0;
	p = va_arg(args, void *);
	if (!p)
	{
		count += (int)write(1, "(nil)", 5);
		return (count);
	}
	x_binary = "0123456789abcdef";
	count += (int)write(1, "0x", 2);
	putnbr_p((unsigned long)p, x_binary, &count);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:08:41 by hjang             #+#    #+#             */
/*   Updated: 2024/12/28 16:00:29 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_word(char c, va_list args)
{
	int	len;

	if (c == 'c')
		len = word_c(args);
	else if (c == 's')
		len = word_s(args);
	else if (c == 'p')
		len = word_p(args);
	else if (c == 'd' || c == 'i')
		len = word_d(args);
	else if (c == 'u')
		len = word_u(args);
	else if (c == 'x' || c == 'X')
		len = word_x(c, args);
	else if (c == '%')
		len = (int)write(1, "%", 1);
	else if (c == '\0')
		len = -1;
	else
	{
		len = (int)write(1, "%", 1);
		len += (int)write(1, &c, 1);
	}
	return (len);
}

static void	check_percent(const char *format, va_list args, int *count)
{
	int	index;
	int	tmp;

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
			tmp = check_word(format[++index], args);
		else
			tmp = (int)write (1, &format[index], 1);
		if (tmp == -1 || (*count > (INT_MAX - tmp)))
		{
			*count = -1;
			return ;
		}
		*count += tmp;
		index++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	check_percent(format, args, &count);
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int x, y;
// 	x = printf("%d\n", -2147483648);
// 	y = ft_printf("%d\n", -2147483648);
// 	printf("\nx = %d\ny = %d\n", x, y);
// 	return (0);
// }

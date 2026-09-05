/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:08:25 by hjang             #+#    #+#             */
/*   Updated: 2024/12/17 15:59:29 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define INT_MAX 2147483647

int		ft_printf(const char *format, ...);
int		word_c(va_list args);
int		word_p(va_list args);
int		word_d(va_list args);
int		word_s(va_list args);
int		word_u(va_list args);
int		word_x(char c, va_list args);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

#endif
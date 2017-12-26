/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:59:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/12/22 15:59:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <printf.h>

size_t	find_conversions(const char *format)
{
	size_t	len;

	len = 0;
	while (format[len] != 's' &&
			format[len] != 'S' &&
			format[len] != 'p' &&
			format[len] != 'd' &&
			format[len] != 'D' &&
			format[len] != 'i' &&
			format[len] != 'o' &&
			format[len] != 'O' &&
			format[len] != 'u' &&
			format[len] != 'U' &&
			format[len] != 'x' &&
			format[len] != 'X' &&
			format[len] != 'c' &&
			format[len] != 'C' &&
			format[len])
		len++;
	return (len);
}

void	fill_specification(t_specification *specification)
{
	specification->flags.minus = FALSE;
	specification->flags.plus = FALSE;
	specification->flags.space = FALSE;
	specification->flags.hash = FALSE;
	specification->flags.zero = FALSE;
	specification->width = 0;
	specification->precision = 0;
	specification->modifier = ft_strnew(2);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_specification	specification;

	g_return = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
			{
				fill_specification(&specification);
				ft_putstr("XXX");
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	ft_strdel(&specification.modifier);
	return (g_return);
}

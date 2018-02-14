/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:40:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/04 18:40:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static size_t			set_color(const char *format)
{
	size_t	step;

	step = 0;
	while (format[step] != '}')
		step++;
	step++;
	if (!ft_strncmp(format, "{red}", step))
		ft_putstr("\033[31m");
	else if (!ft_strncmp(format, "{yellow}", step))
		ft_putstr("\033[33m");
	else if (!ft_strncmp(format, "{green}", step))
		ft_putstr("\033[32m");
	else if (!ft_strncmp(format, "{normal}", step))
		ft_putstr("\033[0m");
	return (step);
}

static t_conversions	get_conversion(const char *format, va_list *ap,
																size_t *step)
{
	t_conversions	conversion;

	conversion.spec = get_specification(format, ap, &conversion.data, step);
	if (conversion.spec.type != '%')
		conversion.data = va_arg(*ap, void *);
	conversion.foo = get_foo(conversion.spec.type);
	return (conversion);
}

int						ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conversions	conversion;
	size_t			step;

	va_start(ap, format);
	g_return = 0;
	while (*format != '\0')
		if (*format == '%')
		{
			conversion = get_conversion(format, &ap, &step);
			conversion.foo(conversion.data, &conversion.spec);
			ft_strdel(&conversion.spec.modifier);
			format += step;
		}
		else if (*format == '{')
			format += set_color(format);
		else
		{
			ft_putchar(*format++);
			g_return++;
		}
	va_end(ap);
	return (g_return);
}

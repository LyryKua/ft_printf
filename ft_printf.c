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

static size_t	set_color(const char *format)
{
	char	*color;
	size_t	i;

	i = 0;
	while (format[i] != '}')
		i++;
	color = ft_strsub(format, 1, i - 1);
	if (!ft_strcmp(color, "red"))
		ft_putstr("\033[31m");
	else if (!ft_strcmp(color, "yellow"))
		ft_putstr("\033[33m");
	else if (!ft_strcmp(color, "green"))
		ft_putstr("\033[32m");
	else if (!ft_strcmp(color, "normal"))
		ft_putstr("\033[0m");
	else
		return (0);
	return (++i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conversions	conversion;
	size_t			step;

	va_start(ap, format);
	g_return = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			conversion.data = va_arg(ap, void *);
			conversion.spec = get_specification(format, &ap, &conversion.data, &step); // should change
			conversion.foo = get_foo(conversion.spec.type);
			conversion.foo(conversion.data, &conversion.spec);
			ft_putstr("{type}");
			format += step;
		}
		else
		{
			ft_putchar(*format++);
			g_return++;
		}
	}
	va_end(ap);
	return (g_return);
}

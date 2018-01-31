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
	return (++i);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*replacing_spec;

	replacing_spec = NULL;
	va_start(ap, format);
	g_return = 0;
	while (*format)
	{
		if (*format == '%')
		{
			replacing_spec = get_replacing_specification(format);
			parse_print(replacing_spec, ap);
			format += ft_strlen(replacing_spec);
		}
		else
		{
			if (*format == '{')
				format += set_color(format);
			ft_putchar(*format++);
			g_return++;
		}
		ft_strdel(&replacing_spec);
	}
	va_end(ap);
	return (g_return);
}

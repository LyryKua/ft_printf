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

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conversions	conversion;
	size_t			step;

	va_start(ap, format);
	g_return = 0;
	while (*format != '\0')
		if (*format == '%')
		{
			conversion.spec = get_specification(format, &ap, &conversion.data,
																		&step);
			if (conversion.spec.type != '%')
				conversion.data = va_arg(ap, void *);
			conversion.foo = get_foo(conversion.spec.type);
			conversion.foo(conversion.data, &conversion.spec);
			ft_strdel(&conversion.spec.modifier);
			format += step;
		}
		else
		{
			ft_putchar(*format++);
			g_return++;
		}
	va_end(ap);
	return (g_return);
}

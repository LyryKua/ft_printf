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

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	void	*data;
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
			ft_putchar(*format++);
			g_return++;
		}
		if (replacing_spec != NULL)
			ft_strdel(&replacing_spec);
	}
	va_end(ap);
	return (g_return);
}

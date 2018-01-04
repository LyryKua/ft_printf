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

void	parse_print(char *specification, void *data)
{
	ft_putstr("XXX");
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	void	*data;
	char	*specification;

	specification = NULL;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			specification = get_specification(format);
			data = va_arg(ap, void *);
			parse_print(specification, data);
			format += ft_strlen(specification);
		}
		else
		{
			ft_putchar(*format++);
			g_return++;
		}
		if (specification != NULL)
			ft_strdel(&specification);
	}
	va_end(ap);
	return (g_return);
}

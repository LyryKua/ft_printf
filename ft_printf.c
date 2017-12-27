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

t_specification	get_new_specification(void)
{
	t_specification specification;

	specification.flags.minus = FALSE;
	specification.flags.plus = FALSE;
	specification.flags.space = FALSE;
	specification.flags.hash = FALSE;
	specification.flags.zero = FALSE;
	specification.width = 0;
	specification.precision = 0;
	specification.modifier.value = ft_strnew(2);
	specification.modifier.priority = ZERO;
	specification.type = FALSE;
	return (specification);
}

void	print(t_specification *specification)
{
	if (specification->type == 's')
		ft_putstr(" [s -> STR] ");
	else if (specification->type == 'S')
		ft_putstr(" [s -> STR] ");
	else if (specification->type == 'p')
		ft_putstr(" [p -> POINTER] ");
	else if (specification->type == 'd')
		ft_putstr(" [d -> DIGIT] ");
	else if (specification->type == 'D')
		ft_putstr(" [D -> DIGIT] ");
	else if (specification->type == 'i')
		ft_putstr(" [i -> DIGIT] ");
	else if (specification->type == 'o')
		ft_putstr(" [o -> OCTET] ");
	else if (specification->type == 'O')
		ft_putstr(" [O -> OCTET] ");
	else if (specification->type == 'u')
		ft_putstr(" [u -> U] ");
	else if (specification->type == 'U')
		ft_putstr(" [U -> U] ");
	else if (specification->type == 'x')
		ft_putstr(" [x -> HEX] ");
	else if (specification->type == 'X')
		ft_putstr(" [X -> HEX] ");
	else if (specification->type == 'U')
		ft_putstr(" [c -> CHAR] ");
	else if (specification->type == 'C')
		ft_putstr(" [C -> CHAR] ");
	else if (specification->type == '%')
		ft_putstr(" [% -> PERCENT] ");
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_specification specification;

	g_return = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			specification = get_new_specification();
			format++;
			if (*format)
			{
				fill_specification(format, &specification);
				if (specification.type != FALSE)
					print(&specification);
			}
			ft_strdel(&specification.modifier.value);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (g_return);
}

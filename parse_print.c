/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:00:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 13:00:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <printf.h>

#include "inc/ft_printf.h"
#include "libft.h"

t_ptr_func	get_function(char type)
{
	t_ptr_func	foo;

	if (type == 'D' || type == 'd')
		foo = dec_long_long;
	else if (type == 'U' || type == 'u')
		foo = dec_unsigned_long_long;
	else if (type == 'B' || type == 'b')
		foo = bin_unsigned_long_long;
	else if (type == 'O' || type == 'o')
		foo = oct_unsigned_long_long;
	else if (type == 'X' || type == 'x')
		foo = hex_unsigned_long_long;
	else if (type == 'c')
		foo = c_lower_case;
	else if (type == 'C')
		foo = c_upper_case;
	else if (type == 's')
		foo = s_lower_case;
	else if (type == 'S')
		foo = s_upper_case;
	else if (type == 'p')
		foo = p_lower_case;
	return (foo);
}

void			parse_print(char *replacing_spec, va_list *ap)
{
	t_conversions	conversion;

	conversion.data = va_arg(*ap, void *);
	conversion.spec = get_specification(replacing_spec, ap, &conversion.data);
	conversion.foo = get_function(conversion.spec.type);
//	print_data(data, spec);
	conversion.foo(conversion.data, &conversion.spec);
	ft_strdel(&conversion.spec.modifier);
}

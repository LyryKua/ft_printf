/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_foo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:14:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/12 20:14:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func_ptr	get_foo(char type)
{
	t_func_ptr	foo;

	if (type == 'D' || type == 'd' || type == 'i')
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
	else
		foo = empty;
	return (foo);
}

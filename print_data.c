/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:23:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 19:23:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

void	without_len(void *data, t_specification spec)
{
	if (spec.type == 's')
		s_lower_case(data, spec);
	else if (spec.type == 'S')
		s_upper_case(data, spec);
	else if (spec.type == 'p')
		p_lower_case(data, spec);
	else if (spec.type == 'd' || spec.type == 'i')
		dec_long_long((int)data, spec);
	else if (spec.type == 'D')
		dec_long_long((long)data, spec);
	else if (spec.type == 'o')
		oct_unsigned_long_long((unsigned int)data, spec);
	else if (spec.type == 'O')
		oct_unsigned_long_long((unsigned long)data, spec);
	else if (spec.type == 'u')
		dec_unsigned_long_long((unsigned int)data, spec);
	else if (spec.type == 'U')
		dec_unsigned_long_long((unsigned long)data, spec);
	else if (spec.type == 'x' || spec.type == 'X')
		hex_unsigned_long_long((unsigned  int)data, spec);
	else if (spec.type == 'c')
		c_lower_case(data, spec);
	else if (spec.type == 'C')
		c_upper_case(data, spec);
}


void	print_data(void *data, t_specification spec)
{
	if (spec.modifier == NULL)
		without_len(data, spec);
	else
	{
		if (spec.type == 'd' || spec.type == 'i')
			di_with_len(data, spec);
		else if (spec.type == 'o')
			o_with_len(data,spec);
		else if (spec.type == 'u')
			u_with_len(data, spec);
		else if (spec.type == 'x' || spec.type == 'X')
			x_with_len(data, spec);
	}
}

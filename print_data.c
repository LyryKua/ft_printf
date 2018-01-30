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

/*
**  s_lower_case
**  s_upper_case
**  p_lower_case
** di_lower_case
**  d_upper_case
**  o_lower_case
**  o_upper_case
**  u_lower_case
**  u_upper_case
**  x_lower_case
**  x_upper_case
**  c_lower_case
*/

void	print_data(void *data, t_specification spec)
{
	if (spec.modifier == NULL)
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
	else
	{
		if (spec.type == 'd' || spec.type == 'i')
		{
			if (!ft_strcmp(spec.modifier, "hh"))
				dec_long_long((char)data, spec);
			else if (!ft_strcmp(spec.modifier, "h"))
				dec_long_long((short)data, spec);
			else if (!ft_strcmp(spec.modifier, "l"))
				dec_long_long((long)data, spec);
			else if (!ft_strcmp(spec.modifier, "ll"))
				dec_long_long((long)data, spec);
			else if (!ft_strcmp(spec.modifier, "j"))
				dec_long_long((intmax_t)data, spec);
			else if (!ft_strcmp(spec.modifier, "z"))
				dec_long_long((size_t)data, spec);
		}
		else if (spec.type == 'o')
		{
			if (!ft_strcmp(spec.modifier, "hh"))
				oct_unsigned_long_long((unsigned char)data, spec);
			else if (!ft_strcmp(spec.modifier, "h"))
				oct_unsigned_long_long((unsigned short)data, spec);
			else if (!ft_strcmp(spec.modifier, "l"))
				oct_unsigned_long_long((unsigned long)data, spec);
			else if (!ft_strcmp(spec.modifier, "ll"))
				oct_unsigned_long_long((unsigned long long)data, spec);
			else if (!ft_strcmp(spec.modifier, "j"))
				oct_unsigned_long_long((uintmax_t)data, spec);
			else if (!ft_strcmp(spec.modifier, "z"))
				oct_unsigned_long_long((size_t)data, spec);
		}
		else if (spec.type == 'u')
		{
			if (!ft_strcmp(spec.modifier, "hh"))
				dec_unsigned_long_long((unsigned char)data, spec);
			else if (!ft_strcmp(spec.modifier, "h"))
				dec_unsigned_long_long((unsigned short)data, spec);
			else if (!ft_strcmp(spec.modifier, "l"))
				dec_unsigned_long_long((unsigned long)data, spec);
			else if (!ft_strcmp(spec.modifier, "ll"))
				dec_unsigned_long_long((unsigned long long)data, spec);
			else if (!ft_strcmp(spec.modifier, "j"))
				dec_unsigned_long_long((uintmax_t)data, spec);
			else if (!ft_strcmp(spec.modifier, "z"))
				dec_unsigned_long_long((size_t)data, spec);
		}
		else if (spec.type == 'x' || spec.type == 'X')
		{
			if (!ft_strcmp(spec.modifier, "hh"))
				hex_unsigned_long_long((unsigned char)data, spec);
			else if (!ft_strcmp(spec.modifier, "h"))
				hex_unsigned_long_long((unsigned short)data, spec);
			else if (!ft_strcmp(spec.modifier, "l"))
				hex_unsigned_long_long((unsigned long)data, spec);
			else if (!ft_strcmp(spec.modifier, "ll"))
				hex_unsigned_long_long((unsigned long long)data, spec);
			else if (!ft_strcmp(spec.modifier, "j"))
				hex_unsigned_long_long((uintmax_t)data, spec);
			else if (!ft_strcmp(spec.modifier, "z"))
				hex_unsigned_long_long((size_t)data, spec);
		}
	}
}

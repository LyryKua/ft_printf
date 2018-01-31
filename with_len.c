/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:47:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/30 17:47:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

void	di_with_len(void *data, t_specification spec)
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

void	o_with_len(void *data, t_specification spec)
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

void	u_with_len(void *data, t_specification spec)
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

void	x_with_len(void *data, t_specification spec)
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

void	b_with_len(void *data, t_specification spec)
{
	if (!ft_strcmp(spec.modifier, "hh"))
		bin_unsigned_long_long((unsigned char)data, spec);
	else if (!ft_strcmp(spec.modifier, "h"))
		bin_unsigned_long_long((unsigned short)data, spec);
	else if (!ft_strcmp(spec.modifier, "l"))
		bin_unsigned_long_long((unsigned long)data, spec);
	else if (!ft_strcmp(spec.modifier, "ll"))
		bin_unsigned_long_long((unsigned long long)data, spec);
	else if (!ft_strcmp(spec.modifier, "j"))
		bin_unsigned_long_long((uintmax_t)data, spec);
	else if (!ft_strcmp(spec.modifier, "z"))
		bin_unsigned_long_long((size_t)data, spec);
}

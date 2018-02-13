/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:46:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/04 18:46:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	left_align(t_specification *spec, char chr)
{
	ft_putchar(chr);
	g_return++;
	while (spec->width-- > 1)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification *spec, char chr)
{
	while (spec->width-- > 1)
	{
		ft_putchar((char)(spec->flags.zero == true
										|| spec->precision == -1 ? '0' : ' '));
		g_return++;
	}
	ft_putchar(chr);
	g_return++;
}

void		c_lower_case(void *data, t_specification *spec)
{
	char	chr;

	chr = (char)data;
	if (!ft_strcmp(spec->modifier, "l"))
		c_upper_case(data, spec);
	else
	{
		if (spec->flags.minus == true)
			left_align(spec, chr);
		else
			right_align(spec, chr);
	}
}

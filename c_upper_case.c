/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_upper_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:46:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/04 18:46:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	left_align(t_specification spec, unsigned int chr)
{
	ft_putunichar(chr);
	g_return++;
	while (spec.width-- > 1)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, unsigned int chr)
{
	while (spec.width-- > 1)
	{
		ft_putchar(' ');
		g_return++;
	}
	ft_putunichar(chr);
	g_return++;
}

void		c_upper_case(void *data, t_specification spec)
{
	unsigned int	chr;

	chr = (unsigned int)data;
	if (spec.flags.minus == true)
		left_align(spec, chr);
	else
		right_align(spec, chr);
}

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
	int	len;

	len = 1;
	if (chr < 0x80)
		len = 1;
	else if (chr < 0x7ff)
		len = 2;
	else if (chr < 0xffff)
		len = 3;
	else if (chr < 0x1fffff)
		len = 4;
	ft_putunichar(chr);
	g_return += len;
	while (spec.width-- > len)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, unsigned int chr)
{
	int	len;

	len = 1;
	if (chr < 0x80)
		len = 1;
	else if (chr < 0x7ff)
		len = 2;
	else if (chr < 0xffff)
		len = 3;
	else if (chr < 0x1fffff)
		len = 4;
	while (spec.width-- > len)
	{
		ft_putchar(' ');
		g_return++;
	}
	ft_putunichar(chr);
	g_return += len;
}

void		c_upper_case(unsigned int chr, t_specification spec)
{
	if (spec.flags.minus == true)
		left_align(spec, chr);
	else
		right_align(spec, chr);
}

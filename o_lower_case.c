/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:53:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/09 16:53:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	o_print(t_specification spec, char *str)
{
	while (spec.precision-- > (int)ft_strlen(str))
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += ft_strlen(str);
}

static void	left_align(t_specification spec, char *str)
{
	o_print(spec, str);
	ft_putstr("[left_align]");
}

static void	right_align(t_specification spec, char *str)
{
	int	len;

	len = (int)ft_strlen(str);
	if (spec.flags.hash == true)
		if (len > spec.precision)
			spec.width--;
	while (spec.width-- > (spec.precision > len ? spec.precision : len))
	{
		ft_putchar(' ');
		g_return++;
	}
	if (spec.flags.hash == true && ft_strcmp(str, "0"))
	{
		ft_putchar('0');
		spec.precision--;
		g_return++;
	}
	o_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	ft_putstr("[fill_zero]");
	ft_putstr(str);
}

void		o_lower_case(void *data, t_specification spec)
{
	unsigned int	nbr;
	char			*str;

	nbr = (unsigned int)data;
	str = ft_uitoa_base(nbr, OCT);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

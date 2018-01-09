/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/09 14:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	u_print(t_specification spec, char *str)
{
	if (spec.flags.plus == true || spec.flags.space == true)
	{
		ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		ft_putstr(str);
	}
	else
		ft_putstr(str);
	g_return += ft_strlen(str);
}

static void	left_align(t_specification spec, char *str)
{
	u_print(spec, str);
	while (spec.width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, char *str)
{
	while (spec.width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	u_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	if (spec.flags.plus == true || spec.flags.space == true)
		ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
	else
		ft_putchar('0');
	g_return++;
	while (spec.width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += ft_strlen(str);
}

void		u_lower_case(void *data, t_specification spec)
{
	unsigned int	nbr;
	char			*str;
	size_t			nbrlen;

	nbr = (unsigned int)data;
	str = ft_uitoa_base(nbr, DEC);
	nbrlen = ft_strlen(str) + 1;
	spec.width = spec.width > nbrlen ? spec.width - (int)nbrlen : 0;
	if (spec.flags.plus == false && spec.flags.space == false &&
		spec.flags.zero == false)
		spec.width++;
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

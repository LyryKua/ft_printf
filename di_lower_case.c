/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_lower_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:41:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/06 12:41:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	di_print(t_specification spec, int nbr, char *str)
{
	if (spec.flags.plus == true || spec.flags.space == true)
	{
		if (nbr >= 0)
		{
			ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
			ft_putstr(str);
		}
		else
			ft_putstr(str);
	}
	else
		ft_putstr(str);
	g_return += ft_strlen(str);
}

static void	left_align(t_specification spec, int nbr, char *str)
{
	di_print(spec, nbr, str);
	while (spec.width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, int nbr, char *str)
{
	while (spec.width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	di_print(spec, nbr, str);
}

static void	fill_zero(t_specification spec, int nbr, char *str)
{
	if (spec.flags.plus == true || spec.flags.space == true || nbr < 0)
		if (nbr >= 0)
			ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		else
		{
			ft_putchar('-');
			str++;
		}
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

void		di_lower_case(void *data, t_specification spec)
{
	int		nbr;
	char	*str;
	size_t	nbrlen;

	nbr = (int)data;
	str = ft_itoa(nbr);
	nbrlen = ft_strlen(str) + (nbr < 0 ? 0 : 1);
	spec.width = spec.width > nbrlen ? spec.width - (int)nbrlen : 0;
	if (spec.flags.plus == false && spec.flags.space == false &&
			spec.flags.zero == false && nbr >= 0)
		spec.width++;
	if (spec.flags.minus == true)
		left_align(spec, nbr, str);
	else if (spec.flags.zero == false)
		right_align(spec, nbr, str);
	else
		fill_zero(spec, nbr, str);
	ft_strdel(&str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_upper_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:07:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/09 17:07:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	x_print(t_specification spec, char *str)
{
	if ((spec.flags.plus == true || spec.flags.space == true) && str[0] != '-')
	{
		ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		g_return++;
	}
	else if (str[0] == '-')
	{
		ft_putchar(*str++);
		g_return++;
	}
	while (spec.precision-- > ft_strlen(str))
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += ft_strlen(str);
}

static void	left_align(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if (spec.flags.plus == true || spec.flags.space == true)
		width--;
	x_print(spec, str);
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if (spec.flags.plus || spec.flags.space || spec.precision == len)
		width--;
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	x_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if (spec.flags.plus == true || spec.flags.space == true || str[0] == '-')
	{
		if (str[0] != '-')
			ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		else
		{
			ft_putchar('-');
			str++;
		}
		g_return++;
	}
	while (width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += ft_strlen(str);
}

void		x_upper_case(void *data, t_specification spec)
{
	unsigned long	nbr;
	char			*str;

	nbr = (unsigned long)data;
	str = ft_uitoa_base(nbr, HEX);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

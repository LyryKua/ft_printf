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

static void	di_print(t_specification spec, char *str)
{
	if ((spec.flags.plus == true || spec.flags.space == true) && *str != '-')
	{
		ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		g_return++;
	}
	else if (*str == '-')
	{
		ft_putchar(*str++);
		g_return++;
	}
	while (spec.precision-- > (int)ft_strlen(str))
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += (int)ft_strlen(str);
}

static void	left_align(t_specification spec, char *str)
{
	int	len;

	if (spec.precision == -1 && !ft_strcmp(str, "0"))
		while (spec.width-- > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	else
	{
		di_print(spec, str);
		len = (int)ft_strlen(str);
		if ((spec.flags.plus == true || spec.flags.space == true) &&
			str[0] != '-')
			spec.width--;
		if (str[0] == '-' && spec.precision - len >= 0)
			spec.width--;
		while (spec.width-- > (spec.precision > len ? spec.precision : len))
		{
			ft_putchar(' ');
			g_return++;
		}
	}
}

static void	right_align(t_specification spec, char *str)
{
	int	len;
	int	width;

	len = (int)ft_strlen(str);
	width = spec.width;
	if ((spec.flags.plus == true || spec.flags.space == true) && str[0] != '-')
		width--;
	if (str[0] == '-' && spec.precision - len >= 0)
		width--;
	while (width-- > (spec.precision > len ? spec.precision : len))
	{
		ft_putchar(' ');
		g_return++;
	}
	if (spec.precision == -1 && !ft_strcmp(str, "0"))
	{
		if (spec.width > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
		return ;
	}
	di_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	int	len;
	int	width;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if ((spec.flags.plus == true || spec.flags.space == true) && *str != '-')
	{
		ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
		width--;
		g_return++;
	}
	else if (*str == '-')
	{
		ft_putchar(*str++);
		g_return++;
	}
	if (str[0] == '-' && spec.precision - len >= 0)
		width--;
	while (width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += (int)ft_strlen(str);
}

void		di_lower_case(int nbr, t_specification spec)
{
	char	*str;

	str = ft_itoa_base(nbr, DEC);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

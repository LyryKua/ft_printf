/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_unsigned_long_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:31:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/31 15:31:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	o_print(t_specification spec, char *str)
{
	if (spec.flags.hash == true)
	{
		spec.precision--;
		ft_putchar('0');
		g_return++;
	}
	if (spec.flags.hash == true && spec.precision <= 0 && spec.width == 0)
		return ;
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
	int	width;
	int	len;

	if (spec.precision == -1 && !ft_strcmp(str, "0"))
	{
		if (spec.width > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
		return ;
	}
	o_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width;
	if (spec.flags.hash == true && spec.precision == 0)
		width--;
	if (spec.width > spec.precision && spec.flags.hash == true &&
		len >= spec.precision && spec.precision != 0)
		width--;
	while (width-- > (spec.precision > len ? spec.precision : len))
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
	width = spec.width;
	if (spec.flags.hash == true && spec.precision == 0)
		width--;
	if (spec.width > spec.precision && spec.flags.hash == true &&
		len >= spec.precision)
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
	o_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	int	len;
	int	width;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if (spec.flags.hash == true)
	{
		width--;
		ft_putchar('0');
		g_return++;
	}
	while (width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += (int)ft_strlen(str);
}

void		bin_unsigned_long_long(unsigned long long nbr, t_specification spec)
{
	char	*str;

	str = ft_ulltoa_base(nbr, BIN);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

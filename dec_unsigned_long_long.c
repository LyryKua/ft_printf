/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_unsigned_long_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:46:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/31 15:20:47 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	dec_print(t_specification spec, char *str)
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
	int	width;
	int	len;

	if (spec.precision == -1 && !ft_strcmp(str, "0"))
		while (spec.width-- > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	else
	{
		dec_print(spec, str);
		len = (int)ft_strlen(str);
		width = spec.width - (spec.precision > len ? spec.precision : len);
		while (width-- > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	}
}

static void	right_align(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	while (width-- > 0)
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
	dec_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	while (width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += ft_strlen(str);
}

void		dec_unsigned_long_long(unsigned long long nbr, t_specification spec)
{
	char	*str;

	str = ft_ulltoa_base(nbr, DEC);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

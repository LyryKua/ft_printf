/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_unsigned_long_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:57:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/31 15:23:04 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	o_print(t_specification spec, char *str)
{
	if (spec.precision == -1)
	{
		spec.width != 0 ? ft_putchar(' ') : 0;
		g_return += spec.width != 0 ? 1 : 0;
		return ;
	}
	if (!ft_strcmp(str, "0"))
	{
		ft_putchar('0');
		g_return++;
		return ;
	}
	if (spec.flags.hash == true)
	{
		ft_putchar('0');
		spec.precision--;
		g_return++;
	}
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

	o_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width
			- len
			- (spec.flags.hash == true ? 1 : 0);
	if (spec.precision < width)
		width -= spec.precision;
	if (!ft_strcmp(str, "0")
		&& spec.flags.hash
		&& spec.flags.zero == false
		&& spec.flags.minus == false
		&& spec.flags.plus == false
		&& spec.flags.space == false)
		width += 1;
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
	width = spec.width - len
			- (spec.flags.hash == true ? 1 : 0);
	if (!ft_strcmp(str, "0")
		&& spec.flags.hash
		&& spec.flags.zero == false
		&& spec.flags.minus == false
		&& spec.flags.plus == false
		&& spec.flags.space == false)
		width += 1;
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
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

void		oct_unsigned_long_long(unsigned long long nbr, t_specification spec)
{
	char	*str;

	str = ft_ulltoa_base(nbr, OCT);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

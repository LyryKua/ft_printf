/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:17:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/28 16:25:50 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	p_print(t_specification spec, char *str)
{
	ft_putstr("0x");
	g_return += 2;
	if (spec.precision == -1 && !ft_strcmp(str, "0"))
		return ;
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
	int	width;
	int	len;

	p_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len) - 2;
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
	width = spec.width
			- (spec.precision > len ? spec.precision : len)
			+ (spec.precision == -1 ? 1 : 0)
			- 2;
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	p_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	ft_putstr("[fill_zero");
	p_print(spec, str);
}

void		p_lower_case(unsigned long long ptr, t_specification spec)
{
	char				*str;

	str = ft_ultoa_base(ptr, HEX);
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}

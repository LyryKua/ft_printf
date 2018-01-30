/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:53:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/09 16:53:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	x_print(t_specification spec, char *str)
{
	if (spec.flags.hash == true && spec.precision <= 0 && spec.width == 0)
	{
		ft_putchar('0');
		g_return++;
		return ;
	}
	if (spec.flags.hash == true && ft_strcmp(str, "0"))
	{
		ft_putstr("0x");
		g_return += 2;
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

	if (spec.precision == -1 && !ft_strcmp(str, "0"))
	{
		if (spec.width > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
		return ;
	}
	x_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width;
	if (spec.flags.hash == true && spec.precision == 0)
		width -= 2;
	if (spec.width > spec.precision && spec.flags.hash == true &&
			spec.precision != 0)
		width -= 2;
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
		width -= 2;
	if (spec.width > spec.precision && spec.flags.hash == true)
		width -= 2;
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
	x_print(spec, str);
}

static void	fill_zero(t_specification spec, char *str)
{
	int	len;
	int	width;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > len ? spec.precision : len);
	if (spec.flags.hash == true)
	{
		width -= 2;
		ft_putstr("0x");
		g_return += 2;
	}
	while (width-- > 0)
	{
		ft_putchar('0');
		g_return++;
	}
	ft_putstr(str);
	g_return += (int)ft_strlen(str);
}

void		x_lower_upper_case(void *data, t_specification spec)
{
	unsigned int	nbr;
	char			*str;
	size_t			i;

	nbr = (unsigned int)data;
	str = ft_uitoa_base(nbr, HEX);
	if (spec.type == 'X')
	{
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = (char)ft_toupper(str[i]);
			i++;
		}
	}
	if (spec.flags.minus == true)
		left_align(spec, str);
	else if (spec.flags.zero == false)
		right_align(spec, str);
	else
		fill_zero(spec, str);
	ft_strdel(&str);
}
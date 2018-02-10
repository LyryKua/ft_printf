/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_long_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:53:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/01 18:02:53 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	hex_print(t_specification spec, char *str)
{
	if (!ft_strcmp(str, "0") && spec.precision == -1)
		return ;
	if (spec.flags.hash == true && ft_strcmp(str, "0"))
	{
		ft_putstr(spec.type == 'X' ? "0X" : "0x");
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

	hex_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width
			- (len > spec.precision ? len : spec.precision);
	if (spec.flags.hash && len > spec.precision && spec.precision == 0)
		width -= 2;
	if (!ft_strcmp(str, "0")
		&& spec.flags.hash
		&& spec.flags.zero == false
		&& spec.flags.minus == false
		&& spec.flags.plus == false
		&& spec.flags.space == false
		&& spec.width != 0)
		width += 2;
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(t_specification spec, char *str)
{
	int width;
	int len;

	len = (int)ft_strlen(str);
	width = spec.width - (len > spec.precision ? len : spec.precision);
	if (spec.flags.hash && len > spec.precision && spec.precision == 0)
		width -= 2;
	if (!ft_strcmp(str, "0") && spec.flags.hash
		&& spec.flags.zero == false
		&& spec.flags.minus == false
		&& spec.flags.plus == false
		&& spec.flags.space == false
		&& spec.width != 0)
		width += 2;
	while (width-- > 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	if (spec.precision == -1 && spec.width != 0)
	{
		ft_putchar(' ');
		g_return++;
	}
	hex_print(spec, str);
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

void		hex_unsigned_long_long(void *data, t_specification *spec)
{
	unsigned long long	nbr;
	char				*str;
	int					i;

	nbr = giv_me_correct_unsigned_nbr(data, spec->modifier, spec->type);
	str = ft_ulltoa_base(nbr, HEX);
	if (spec->type == 'X')
	{
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = (char)ft_toupper(str[i]);
			i++;
		}
	}
	if (spec->flags.minus == true)
		left_align(*spec, str);
	else if (spec->flags.zero == false)
		right_align(*spec, str);
	else
		fill_zero(*spec, str);
	ft_strdel(&str);
}

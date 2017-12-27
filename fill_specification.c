/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_specification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:51:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/12/27 13:51:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void			fill_flags(char flag, t_specification *specification)
{
	if (flag == '-')
		specification->flags.minus = TRUE;
	else if (flag == '+')
		specification->flags.plus = TRUE;
	else if (flag == ' ')
		specification->flags.space = TRUE;
	else if (flag == '#')
		specification->flags.hash = TRUE;
	else
		specification->flags.zero = TRUE;
}

void			fill_modifier_h_hh(const char *modifier, t_specification *specification)
{
	if (!ft_strncmp(modifier, "hh", 2) && specification->modifier.priority < HH)
	{
		ft_strncpy(specification->modifier.value, "hh", 2);
		specification->modifier.priority = HH;
	}
	else if (*modifier == 'h' && specification->modifier.priority < H)
	{
		ft_strncpy(specification->modifier.value, "h\0", 2);
		specification->modifier.priority = H;
	}
}

void			fill_modifier_l_ll(const char *modifier, t_specification *specification)
{
	if (!ft_strncmp(modifier, "ll", 2) && specification->modifier.priority < LL)
	{
		ft_strncpy(specification->modifier.value, "ll", 2);
		specification->modifier.priority = LL;
	}
	else if (*modifier == 'l' && specification->modifier.priority < L)
	{
		ft_strncpy(specification->modifier.value, "l\0", 2);
		specification->modifier.priority = L;
	}
}

void			fill_modifier(const char *modifier, t_specification *specification)
{
	if (*modifier == 'z' && specification->modifier.priority < Z)
	{
		ft_strncpy(specification->modifier.value, "z\0", 2);
		specification->modifier.priority = Z;
	}
	else if (*modifier == 'j' && specification->modifier.priority < J)
	{
		ft_strncpy(specification->modifier.value, "j\0", 2);
		specification->modifier.priority = J;
	}
	else if ((!ft_strncmp(modifier, "ll", 2) && specification->modifier.priority < LL) ||
			(*modifier == 'l' && specification->modifier.priority < L))
		fill_modifier_l_ll(modifier, specification);
	else if ((!ft_strncmp(modifier, "hh", 2) && specification->modifier.priority < HH) ||
			(*modifier == 'h' && specification->modifier.priority < H))
		fill_modifier_h_hh(modifier, specification);

}

void			fill_type(const char type, t_specification *specification)
{
	if (type == 's' || type == 'S' || type == 'p' ||
		type == 'd' || type == 'D' || type == 'i' ||
		type == 'o' || type == 'O' || type == 'u' ||
		type == 'U' || type == 'x' || type == 'X' ||
		type == 'c' || type == 'C' || type == '%')
		specification->type = type;
}

void			fill_specification(const char *format, t_specification *specification)
{
	while (*format)
	{
		if (*format == '-' || *format == '+' || *format == '0' ||
			*format == '#' || *format == ' ')
		{
			fill_flags(*format, specification);
			format++;
			specification->step++;
		}
		else if (*format >= '1' && *format <= '9')
		{
			specification->width = ft_atoi(format);
			while (ft_isdigit(*format))
			{
				format++;
				specification->step++;
			}
		}
		else if (*format == '.')
		{
			format++;
			specification->step++;
			specification->precision = ft_atoi(format);
			while (ft_isdigit(*format))
			{
				format++;
				specification->step++;
			}
		}
		else if (*format == 'z' || *format == 'j' || *format == 'l' ||
				 *format == 'h')
		{
			fill_modifier(format, specification);
			if (!ft_strncmp(format, "ll", 2) || !ft_strncmp(format, "hh", 2))
			{
				format += 2;
				specification->step += 2;
			}
			else
			{
				format++;
				specification->step++;
			}
		}
		else
		{
			fill_type(*format, specification);
			format++;
			specification->step++;
			break ;
		}
	}
}
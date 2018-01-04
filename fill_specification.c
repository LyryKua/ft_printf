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

#define F	format
#define S	spec->step
#define FS	F[S]
#define CMP	ft_strncmp

void	fill_flags(char flag, t_specification *spec)
{
	if (flag == '-')
		spec->flags.minus = TRUE;
	else if (flag == '+')
		spec->flags.plus = TRUE;
	else if (flag == ' ')
		spec->flags.space = TRUE;
	else if (flag == '#')
		spec->flags.hash = TRUE;
	else
		spec->flags.zero = TRUE;
	if (spec->flags.minus == TRUE && spec->flags.zero == TRUE)
		spec->flags.zero = FALSE;
}

void	fill_type(const char type, t_specification *spec)
{
	if (type == 's' || type == 'S' || type == 'p' ||
		type == 'd' || type == 'D' || type == 'i' ||
		type == 'o' || type == 'O' || type == 'u' ||
		type == 'U' || type == 'x' || type == 'X' ||
		type == 'c' || type == 'C' || type == '%')
		spec->type = type;
}

void	fill_specification(const char *format, t_specification *spec)
{
	while (FS)
		if (FS == '-' || FS == '+' || FS == '0' || FS == '#' || FS == ' ')
			fill_flags(F[S++], spec);
		else if (FS >= '1' && FS <= '9')
		{
			spec->width = ft_atoi(F + S);
			while (ft_isdigit(FS))
				S++;
		}
		else if (FS == '.')
		{
			spec->precision = ft_atoi(F + ++S);
			while (ft_isdigit(FS))
				S++;
		}
		else if (FS == 'z' || FS == 'j' || FS == 'l' || FS == 'h')
		{
			fill_modifier(F + S, spec);
			S += (!CMP(F + S, "ll", 2) || !CMP(F + S, "hh", 2)) ? 2 : 1;
		}
		else
		{
			fill_type(F[S++], spec);
			break ;
		}
}

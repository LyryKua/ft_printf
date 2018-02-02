/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:11:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 13:11:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft.h"

static t_flag	get_flags(char *rep_spec)
{
	t_flag	flags;

	flags.hash = false;
	flags.zero = false;
	flags.minus = false;
	flags.plus = false;
	flags.space = false;
	rep_spec++;
	while (*rep_spec == '#' || *rep_spec == '0' || *rep_spec == '-' ||
			*rep_spec == '+' || *rep_spec == ' ')
	{
		if (*rep_spec == '#')
			flags.hash = true;
		else if (*rep_spec == '0')
			flags.zero = true;
		else if (*rep_spec == '-')
			flags.minus = true;
		else if (*rep_spec == '+')
			flags.plus = true;
		else if (*rep_spec == ' ')
			flags.space = true;
		rep_spec++;
	}
	return (flags);
}

static int		get_width(char *replacing_spec, va_list ap, void **data,
														t_flag *flags)
{
	int	width;

	while ((*replacing_spec == '0' || !ft_isdigit(*replacing_spec))
			&& *replacing_spec != '*'
			&& *replacing_spec != '.'
			&& *replacing_spec)
		replacing_spec++;
	if (*replacing_spec == '*')
	{
		width = (int)*data;
		*data = va_arg(ap, void *);
	}
	else if (*replacing_spec == '\0')
		width = 0;
	else
		width = ft_atoi(replacing_spec);
	if (width < 0)
	{
		width = ft_abs(width);
		flags->minus = true;
	}
	return (width);
}

static int		get_precision(char *replacing_spec, t_flag *flags)
{
	int	precision;
	int	len;

	len = (int)ft_strlen(replacing_spec);
	while (replacing_spec[len - 1] != '.' && len > 0)
		len--;
	precision = 0;
	if (*(replacing_spec + len) != '0' && ft_isdigit(*(replacing_spec + len)))
		precision = len > 0 ? ft_atoi(replacing_spec + len) : 0;
	else if (len > 0)
		precision = -1;
	if (precision != 0)
		flags->zero = false;
	return (precision);
}

static char		*get_modifier(char *replacing_spec)
{
	char	*modifier;

	if (ft_strstr(replacing_spec, "z"))
		modifier = ft_strdup("z");
	else if (ft_strstr(replacing_spec, "j"))
		modifier = ft_strdup("j");
	else if (ft_strstr(replacing_spec, "ll"))
		modifier = ft_strdup("ll");
	else if (ft_strstr(replacing_spec, "l"))
		modifier = ft_strdup("l");
	else if (ft_strstr(replacing_spec, "h") && !ft_strstr(replacing_spec, "hh"))
		modifier = ft_strdup("h");
	else if (ft_strstr(replacing_spec, "hh"))
		modifier = ft_strdup("hh");
	else
		modifier = NULL;
	return (modifier);
}

t_specification	get_specification(char *replacing_spec, va_list ap, void **data)
{
	t_specification	spec;

	spec.flags = get_flags(replacing_spec);
	spec.width = get_width(replacing_spec, ap, data, &spec.flags);
	spec.precision = get_precision(replacing_spec, &spec.flags);
	spec.modifier = get_modifier(replacing_spec);
	spec.type = replacing_spec[ft_strlen(replacing_spec) - 1];
	spec.flags.zero = (spec.flags.zero && spec.flags.minus) ?
														false : spec.flags.zero;
	return (spec);
}

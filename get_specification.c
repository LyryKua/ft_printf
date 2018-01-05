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

t_flag			get_flags(char *replacing_spec)
{
	t_flag	flags;

	flags.hash = false;
	flags.zero = false;
	flags.minus = false;
	flags.plus = false;
	flags.space = false;
	while (*replacing_spec == '#' || *replacing_spec == '0' ||
			*replacing_spec == '-' || *replacing_spec == '+' ||
			*replacing_spec == ' ')
	{
		if (*replacing_spec == '#')
			flags.hash = true;
		else if (*replacing_spec == '0')
			flags.zero = true;
		else if (*replacing_spec == '-')
			flags.minus = true;
		else if (*replacing_spec == '+')
			flags.plus = true;
		else if (*replacing_spec == ' ')
			flags.space = true;
		replacing_spec++;
	}
	return (flags);
}

int				get_width(char *replacing_spec)
{
	while (*replacing_spec == '0' || !ft_isdigit(*replacing_spec))
		replacing_spec++;
	return (*replacing_spec == '\0' ? 0 : ft_atoi(replacing_spec));
}

int				get_precision(char *replacing_spec)
{
	while (*replacing_spec != '.' && *replacing_spec)
		replacing_spec++;
	return (*replacing_spec == '.' ? ft_atoi(++replacing_spec) : 0);
}

char			*get_modifier(char *replacing_spec)
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

t_specification	get_specification(char *replacing_spec)
{
	t_specification	spec;

	spec.flags = get_flags(++replacing_spec);
	spec.width = get_width(replacing_spec);
	spec.precision = get_precision(replacing_spec);
	spec.modifier = get_modifier(replacing_spec);
	spec.type = replacing_spec[ft_strlen(replacing_spec) - 1];
	return (spec);
}

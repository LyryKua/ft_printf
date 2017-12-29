/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_modifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:59:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/12/29 16:59:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	fill_modifier_h_hh(const char *modifier, t_specification *spec)
{
	if (!ft_strncmp(modifier, "hh", 2) && spec->modifier.priority < HH)
	{
		ft_strncpy(spec->modifier.value, "hh", 2);
		spec->modifier.priority = HH;
	}
	else if (*modifier == 'h' && spec->modifier.priority < H)
	{
		ft_strncpy(spec->modifier.value, "h\0", 2);
		spec->modifier.priority = H;
	}
}

static void	fill_modifier_l_ll(const char *modifier, t_specification *spec)
{
	if (!ft_strncmp(modifier, "ll", 2) && spec->modifier.priority < LL)
	{
		ft_strncpy(spec->modifier.value, "ll", 2);
		spec->modifier.priority = LL;
	}
	else if (*modifier == 'l' && spec->modifier.priority < L)
	{
		ft_strncpy(spec->modifier.value, "l\0", 2);
		spec->modifier.priority = L;
	}
}

void		fill_modifier(const char *modifier, t_specification *spec)
{
	if (*modifier == 'z' && spec->modifier.priority < Z)
	{
		ft_strncpy(spec->modifier.value, "z\0", 2);
		spec->modifier.priority = Z;
	}
	else if (*modifier == 'j' && spec->modifier.priority < J)
	{
		ft_strncpy(spec->modifier.value, "j\0", 2);
		spec->modifier.priority = J;
	}
	else if ((!ft_strncmp(modifier, "ll", 2) && spec->modifier.priority < LL) ||
			(*modifier == 'l' && spec->modifier.priority < L))
		fill_modifier_l_ll(modifier, spec);
	else if ((!ft_strncmp(modifier, "hh", 2) && spec->modifier.priority < HH) ||
			(*modifier == 'h' && spec->modifier.priority < H))
		fill_modifier_h_hh(modifier, spec);
}

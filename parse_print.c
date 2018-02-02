/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:00:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 13:00:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "inc/ft_printf.h"
#include "libft.h"

void	parse_print(char *replacing_spec, va_list ap)
{
	void			*data;
	t_specification	spec;

	data = va_arg(ap, void *);
	spec = get_specification(replacing_spec, ap, &data);
	print_data(data, spec);
	ft_strdel(&spec.modifier);
}

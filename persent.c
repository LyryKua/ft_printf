/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:41:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/09 14:41:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

void		empty(void *data, t_specification *spec)
{
	if (spec->type == '%')
		c_lower_case((void *)'%', spec);
	data = NULL;
}

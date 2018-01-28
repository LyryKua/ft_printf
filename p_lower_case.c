/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:17:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/28 12:17:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		p_lower_case(void *data, t_specification spec)
{
	unsigned long	ptr;
	char			*str;

	ptr = (unsigned long)data;
	str = ft_ultoa_base(ptr, HEX);
	if ()
}

//void	p_lower_case(void *data, t_specification spec)
//{
//	x_upper_case(data, spec);
//}
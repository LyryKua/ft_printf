/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:23:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 19:23:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft.h"

void	s_lower_case(void *data, t_specification spec)
{
	ft_putstr("data");
}

void	s_upper_case(void *data, t_specification spec)
{
	ft_putstr("data");
}

void	p_lower_case(void *data, t_specification spec)
{
	ft_putstr("data");
}

/*
** di_lower_case
** d_upper_case
** o_lower_case
** o_upper_case
** u_lower_case
** u_upper_case
** x_lower_case
** x_upper_case
*/

void	c_lower_case(void *data, t_specification spec)
{
	ft_putstr("data");
}

void	c_upper_case(void *data, t_specification spec)
{
	ft_putstr("data");
}


void	print_data(void *data, t_specification spec)
{
	if (spec.type == 's')
		s_lower_case(data, spec);
	else if (spec.type == 'S')
		s_upper_case(data, spec);
	else if (spec.type == 'p')
		p_lower_case(data, spec);
	else if (spec.type == 'd' || spec.type == 'i')
		di_lower_case(data, spec);
	else if (spec.type == 'D')
		d_upper_case(data, spec);
	else if (spec.type == 'o')
		o_lower_case(data, spec);
	else if (spec.type == 'O')
		o_upper_case(data, spec);
	else if (spec.type == 'u')
		u_lower_case(data, spec);
	else if (spec.type == 'U')
		u_upper_case(data, spec);
	else if (spec.type == 'x')
		x_lower_case(data, spec);
	else if (spec.type == 'X')
		x_upper_case(data, spec);
	else if (spec.type == 'c')
		c_lower_case(data, spec);
	else if (spec.type == 'C')
		c_upper_case(data, spec);
}

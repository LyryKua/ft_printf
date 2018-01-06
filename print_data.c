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
	ft_putendl("data");
}

void	s_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	p_lower_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

/*
** '0' - zero
** '-' - minus
** '+' - plus
** ' ' - space
*/
void	di_lower_case(void *data, t_specification spec)
{
	int		nbr;
	char	*str;
	size_t	nbrlen;

	nbr = (int)data;
	str = ft_itoa(nbr);
	nbrlen = ft_strlen(str) + (nbr < 0 ? 0 : 1);
	spec.width = spec.width > nbrlen ? spec.width - (int)nbrlen : 0;
	while (spec.width-- > 0)
		ft_putchar(' ');
	if (spec.flags.plus == true || spec.flags.space == true)
	{
		if (nbr >= 0)
		{
			ft_putchar((char)(spec.flags.plus == true ? '+' : ' '));
			ft_putstr(str);
		}
		else
			ft_putstr(str);
	}
	else
		ft_putstr(str);
	ft_strdel(&str);
}

void	d_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	o_lower_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	o_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	u_lower_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	u_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	x_lower_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	x_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	c_lower_case(void *data, t_specification spec)
{
	ft_putendl("data");
}

void	c_upper_case(void *data, t_specification spec)
{
	ft_putendl("data");
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_lower_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:41:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/06 12:41:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"



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
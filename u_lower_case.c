/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/09 14:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	u_lower_case(void *data, t_specification spec)
{
	unsigned int	nbr;
	char			*str;
	size_t			nbrlen;

	nbr = (unsigned int)data;
	str = ft_itoa(nbr);
	nbrlen = ft_strlen(str) + (nbr < 0 ? 0 : 1);
	spec.width = spec.width > nbrlen ? spec.width - (int)nbrlen : 0;
	if (spec.flags.plus == false && spec.flags.space == false &&
		spec.flags.zero == false && nbr >= 0)
		spec.width++;
	if (spec.flags.minus == true)
		left_align(spec, nbr, str);
	else if (spec.flags.zero == false)
		right_align(spec, nbr, str);
	else
		fill_zero(spec, nbr, str);
	ft_strdel(&str);
}
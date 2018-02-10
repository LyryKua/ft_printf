/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giv_me_correct_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:26:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/09 16:26:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

long long			giv_me_correct_signed_nbr(void *data, char *modifier, char type)
{
	long long	correct_nbr;

	if (type != 'U' && type != 'D' && type != 'O')
	{
		if (modifier == NULL)
			correct_nbr = (int)data;
		else if (!ft_strcmp(modifier, "hh"))
			correct_nbr = (char)data;
		else if (!ft_strcmp(modifier, "h"))
			correct_nbr = (short)data;
		else if (!ft_strcmp(modifier, "l"))
			correct_nbr = (long)data;
		else if (!ft_strcmp(modifier, "ll"))
			correct_nbr = (long long)data;
		else if (!ft_strcmp(modifier, "j"))
			correct_nbr = (intmax_t)data;
		else
			correct_nbr = (size_t)data;
	}
	else
		correct_nbr = (long long)data;
	return (correct_nbr);
}

unsigned long long	giv_me_correct_unsigned_nbr(void *data, char *modifier, char type)
{
	unsigned long long	correct_nbr;

	if (type != 'U' && type != 'D' && type != 'O')
	{
		if (modifier == NULL)
			correct_nbr = (unsigned int)data;
		else if (!ft_strcmp(modifier, "hh"))
			correct_nbr = (unsigned char)data;
		else if (!ft_strcmp(modifier, "h"))
			correct_nbr = (unsigned short)data;
		else if (!ft_strcmp(modifier, "l"))
			correct_nbr = (unsigned long)data;
		else if (!ft_strcmp(modifier, "ll"))
			correct_nbr = (unsigned long long)data;
		else if (!ft_strcmp(modifier, "j"))
			correct_nbr = (uintmax_t)data;
		else
			correct_nbr = (size_t)data;
	}
	else
		correct_nbr = (unsigned long long)data;
	return (correct_nbr);
}

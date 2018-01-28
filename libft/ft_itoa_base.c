/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:41:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/06 12:41:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert integer to string (non-standard function)
**
** Converts an integer value to a null-terminated string using the specified
** base and stores the result in the array given by str parameter.
**
** If base is 10 and value is negative, the resulting string is preceded with a
** minus sign (-). With any other base, value is always considered unsigned.
**
** -----------------------------------------------------------------------------
**
** value -- Value to be converted to a string.
**
** base -- Numerical base used to represent the value as a string, between 2 and
** 16, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
*/

#include "libft.h"

static size_t	value_len(int value, int base)
{
	size_t	len;

	len = value < 0 ? 2 : 1;
	while (value /= base)
		len++;
	return (len);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*alphabet;
	size_t	len;

	if (value == 0)
		return (ft_strdup("0"));
	alphabet = "0123456789abcdef";
	len = value_len(value, base);
	str = ft_strnew(len);
	while (len)
	{
		str[len-- - 1] = alphabet[ft_abs(value % base)];
		value /= base;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

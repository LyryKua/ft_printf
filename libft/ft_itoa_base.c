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

/*
** 0123456789ABCDEF
*/

#include <string.h>

/*
 * tmp
 */
#include <stdio.h>

static size_t	value_len(int value, int base)
{
	size_t	len;

	while (value /= base)
		len++;
	return (len);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*alphabet;
	size_t	len;

	alphabet = "0123456789ABCDEF";
	len = value_len(value, base);
	printf("%zu\n", len);
	return (str);
}
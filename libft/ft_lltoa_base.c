/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:28:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/31 15:20:01 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	value_len(long long value, int base)
{
	size_t	len;

	len = value < 0 ? 2 : 1;
	while (value /= base)
		len++;
	return (len);
}

char			*ft_lltoa_base(long long value, int base)
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
		str[len-- - 1] = alphabet[ft_llabs(value % base)];
		value /= base;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

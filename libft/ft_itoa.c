/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:14:06 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/15 21:47:37 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static size_t	length_of_number(int nbr)
{
	size_t	length;
	int		flag;

	if (nbr == INT_MIN)
		return (11);
	flag = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		flag = 1;
	}
	length = 1;
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		length++;
	}
	return (flag ? length + 1 : length);
}

static char		*reverse_string(char *str)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	size_t	len;

	len = length_of_number(n);
	if (!(str = ft_strnew(sizeof(char) * (len + 1))))
		return (0);
	if (n == INT_MIN)
	{
		ft_strdel(&str);
		return (ft_strdup("-2147483648"));
	}
	if (n < 0)
	{
		n = -n;
		str[--len] = '-';
	}
	i = 0;
	while (42)
	{
		str[i++] = (char)(n % 10 + '0');
		if ((n /= 10) == 0)
			break ;
	}
	return (reverse_string(str));
}

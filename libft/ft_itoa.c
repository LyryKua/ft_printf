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
	int	length;
	int	flag;

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
	int		len;
	int		i;
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
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (0);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		str[len-- - 1] = '-';
	}
	i = 0;
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	return (reverse_string(str));
}

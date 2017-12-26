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

#include "libft.h"
#include <stdlib.h>

static size_t	ft_numeric(int n)
{
	size_t	numeric;

	numeric = (n <= 0) ? 1 : 0;
	while (n)
	{
		numeric++;
		n = n / 10;
	}
	return (numeric);
}

static char		*ft_reverse(char const *tmp)
{
	char	*s;
	size_t	len;
	int		i;

	len = ft_strlen(tmp);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len)
		s[i++] = tmp[len-- - 1];
	s[i] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		i;
	int		flag;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_numeric(n) + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_reverse("8463847412-"));
	flag = 0;
	if (n < 0)
	{
		flag = 1;
		n = -n;
	}
	i = 0;
	while (n > 9)
	{
		tmp[i++] = n % 10 + '0';
		n /= 10;
	}
	tmp[i++] = n + '0';
	if (flag)
		tmp[i++] = '-';
	tmp[i] = '\0';
	return (ft_reverse(tmp));
}

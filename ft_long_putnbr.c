/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:59:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/03 14:59:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_long_putnbr(long long int n)
{
	char tmp;

	if (n != LLONG_MIN)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n > 9)
			ft_long_putnbr(n / 10);
		tmp = (char)(n % 10 + '0');
		write(1, &tmp, 1);
	}
	else
		write(1, "-9223372036854775808", 20);
}
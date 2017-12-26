/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    length_of_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:20:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/12/25 18:20:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length_of_number(int nbr)
{
	int	length;
	int	flag;

	if (nbr == -2147483648)
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
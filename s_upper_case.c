/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_upper_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:42:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/27 19:42:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	s_print(unsigned int *str, int len)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		ft_putunichar(str[i++]);
	g_return += len;
}

static void	left_align(int width, unsigned int *str, int len)
{
	s_print(str, len);
	while (width-- > len)
	{
		ft_putchar(' ');
		g_return++;
	}
}

static void	right_align(int width, unsigned int *str, int len)
{
	while (width-- > len)
	{
		ft_putchar(' ');
		g_return++;
	}
	s_print(str, len);
}

void		s_upper_case(unsigned int *str, t_specification spec)
{
	int				len;
	size_t			i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 0x80)
			len += 1;
		else if (str[i] < 0x7ff)
			len += 2;
		else if (str[i] < 0xffff)
			len += 3;
		else if (str[i] < 0x1fffff)
			len += 4;
		i++;
	}
	if (spec.flags.minus == true)
		left_align(spec.width, str, len);
	else
		right_align(spec.width, str, len);
}

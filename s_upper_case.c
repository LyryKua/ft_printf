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

static int	operand(unsigned int nbr)
{
	int	op;

	if (nbr < 0x80)
		op = 1;
	else if (nbr < 0x7ff)
		op = 2;
	else if (nbr < 0xffff)
		op = 3;
	else if (nbr < 0x1fffff)
		op = 4;
	return (op);
}

void		s_upper_case(void *data, t_specification *spec)
{
	int				len;
	size_t			i;
	unsigned int	*str;

	str = (unsigned int *)data;
	if (str == NULL)
	{
		ft_putstr("(null)");
		g_return += 6;
		return ;
	}
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len += operand(str[i]);
		i++;
	}
	if (spec->flags.minus == true)
		left_align(spec->width, str, len);
	else
		right_align(spec->width, str, len);
}

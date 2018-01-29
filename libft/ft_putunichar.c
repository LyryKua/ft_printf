/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:34:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/28 18:50:39 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 00000000 -- 0000007F: 	0xxxxxxx
** 00000080 -- 000007FF: 	110xxxxx 10xxxxxx
** 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
** 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

void	ft_putunichar(unsigned int c)
{
	unsigned char *str;

	str = (unsigned char *)ft_memalloc(4);
	if (c < 0x80)
		str[0] = (unsigned char)c;
	else if (c < 0x7ff)
	{
		str[0] = (unsigned char)(0xc0 | (c >> 6));
		str[1] = (unsigned char)(0x80 | (0x3f & c));
	}
	else if (c < 0xffff)
	{
		str[0] = (unsigned char)(0xe0 | (c >> 12));
		str[1] = (unsigned char)(0x80 | (0x3f & (c >> 6)));
		str[2] = (unsigned char)(0x80 | (0x3f & c));
	}
	else if (c < 0x1fffff)
	{
		str[0] = (unsigned char)(0xf0 | (c >> 18));
		str[1] = (unsigned char)(0x80 | (0x3f & (c >> 12)));
		str[2] = (unsigned char)(0x80 | (0x3f & (c >> 6)));
		str[3] = (unsigned char)(0x80 | (0x3f & c));
	}
	ft_putstr((const char *)str);
	ft_memdel((void **)&str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/04 19:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_replacing_specification(const char *format)
{
	char	*replacing_spec;
	size_t	i;

	i = 1;
	while (format[i] != 's'
			&& format[i] != 'S'
			&& format[i] != 'p'
			&& format[i] != 'd'
			&& format[i] != 'D'
			&& format[i] != 'i'
			&& format[i] != 'o'
			&& format[i] != 'O'
			&& format[i] != 'u'
			&& format[i] != 'U'
			&& format[i] != 'x'
			&& format[i] != 'X'
			&& format[i] != 'c'
			&& format[i] != 'C'
			&& format[i] != '%'
			&& format[i] != 'b'
			&& format[i])
		i++;
	replacing_spec = ft_strsub(format, 0, format[i] == '\0' ? i - 1 : i + 1);
	return (replacing_spec);
}

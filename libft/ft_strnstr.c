/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:04:35 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/21 12:10:55 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(l))
		return ((char *)b);
	i = 0;
	while (b[i] && i < len)
	{
		j = 0;
		while (l[j] == b[i + j] && i + j < len)
		{
			if (j == ft_strlen(l) - 1)
				return ((char *)b + i);
			j++;
		}
		i++;
	}
	return (0);
}

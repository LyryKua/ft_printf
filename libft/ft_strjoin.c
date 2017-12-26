/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:51:20 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/21 21:01:45 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (!(t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*t))))
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		t[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		t[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	t[ft_strlen(s1) + i] = '\0';
	return (t);
}

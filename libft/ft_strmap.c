/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:28:43 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/21 20:41:07 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	size_t	i;

	if (!s || !f || !(tmp = (char *)malloc((1 + ft_strlen(s)) * sizeof(*tmp))))
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

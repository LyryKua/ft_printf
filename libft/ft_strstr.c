/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:57:01 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/20 19:31:20 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)big;
	if (little[0] == '\0')
		return (tmp);
	if (ft_strlen(big) >= ft_strlen(little))
	{
		while (tmp)
		{
			if (!(tmp = ft_strchr(tmp, little[0])))
				return (0);
			i = 0;
			while (little[i] && tmp[i] && tmp[i] == little[i])
				i++;
			if (!little[i])
				return (tmp);
			tmp++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:46:38 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/19 20:01:29 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(s1);
	j = 0;
	while (s2[j] && j < n)
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}

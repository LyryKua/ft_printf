/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:36:18 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/23 16:50:52 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	l;
	size_t	j;
	int		k;

	if (!s)
		return (0);
	j = 0;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	l = ft_strlen(s);
	while (l != 1 && (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	k = l - j;
	if (k < 0)
		k = 0;
	return (ft_strsub(s, j, (size_t)k));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:28:50 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/19 19:11:04 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*dst))))
		return (0);
	dst = ft_strcpy(dst, s1);
	return (dst);
}

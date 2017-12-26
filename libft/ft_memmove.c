/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:17:51 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/16 19:49:17 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*s;

	s = dst;
	if (dst > src)
		while (len--)
			((char *)s)[len] = ((char *)src)[len];
	else
		s = ft_memcpy(dst, src, len);
	return (s);
}

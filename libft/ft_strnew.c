/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:40:16 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/21 13:45:02 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (!(fresh = (char *)malloc(size + 1)))
		return (0);
	return (ft_memset(fresh, '\0', size + 1));
}

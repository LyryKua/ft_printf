/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:05:17 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/23 12:48:03 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		if (!(lstnew->content = ft_memalloc(content_size)))
			free(lstnew->content);
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	else
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	lstnew->next = NULL;
	return (lstnew);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:38:07 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/23 11:52:24 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		flag;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		flag = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			flag = 1;
		}
		if (flag)
			words++;
	}
	return (words);
}

static size_t	ft_chars(char const *s, char c)
{
	size_t	chars;

	chars = 0;
	while (s[chars] && s[chars] != c)
		chars++;
	return (chars);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (!s)
		return (0);
	if (!(split = (char **)malloc((ft_words(s, c) + 1) * sizeof(char*))))
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[i] = ft_strsub(s, 0, ft_chars(s, c));
			s += ft_chars(s, c);
			i++;
		}
	}
	split[i] = 0;
	return (split);
}

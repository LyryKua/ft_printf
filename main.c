/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:46:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/04 18:46:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include "ft_printf.h"


int main(void)
{
	setlocale(LC_ALL, "");
	int or = -1, ft = -1;

	or =    printf("   printf:\t|%42C|\n", L'К');
	ft = ft_printf("ft_printf:\t|%42C|\n", L'К');
	printf("or = %d, ft = %d\n", or, ft);

	or =    printf("   printf:\t|%42C|\n", L'😀');
	ft = ft_printf("ft_printf:\t|%42C|\n", L'😀');
	printf("or = %d, ft = %d\n", or, ft);

	or =    printf("   printf:\t|%42C|\n", L'🖕');
	ft = ft_printf("ft_printf:\t|%42C|\n", L'🖕');
	printf("or = %d, ft = %d\n", or, ft);
	return (0);
}



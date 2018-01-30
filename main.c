/* ************************************************************************** */
/*                                                             %              */
/*                                                           %%%%             */
/*   main.c                                                %%%%   %%          */
/*                                                       %%%%   %%%           */
/*   By: khrechen <khrechen@student.unit.ua>            %%%%  %%%    %%       */
/*                                                       %%%      %%%%        */
/*   Created: 2018/01/04 18:46:00 by khrechen              %%%  %%%%          */
/*   Updated: 2018/01/04 18:46:00 by khrechen                %%%%%            */
/*                                                             %              */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include "ft_printf.h"

int	main(void)
{
	setlocale(LC_ALL, "");
	int or = -1, ft = -1;

//	or =    printf("   printf:\t|%20S|\t|%S|\t|%-42S|\n", L"合気道", L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"ድመቶች ሰዎች አልወደውም.");
//	ft = ft_printf("ft_printf:\t|%20S|\t|%S|\t|%-42S|\n", L"合気道", L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"ድመቶች ሰዎች አልወደውም.");
//	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%S|\t|%S|\t|%C|\t|%S|\n", L"Wide sample string..", L"米", L'米', L"");
	ft = ft_printf("ft_printf:\t|%S|\t|%S|\t|%C|\t|%S|\n", L"Wide sample string..", L"米", L'米', L"");
	printf("or = %d\tft = %d\n\n", or, ft);
	while (32);
	return (0);
}

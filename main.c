#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	setlocale(LC_ALL, "");
	int or = -1, ft = -1;

	or =    printf("   printf:\t|%d|\n", 42);
	ft = ft_printf("ft_printf:\t|%d|\n", 42);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%ld|\n", LONG_MAX - 10);
	ft = ft_printf("ft_printf:\t|%ld|\n", LONG_MAX - 10);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%hhd|\n", 15000);
	ft = ft_printf("ft_printf:\t|%hhd|\n", 15000);
	printf("or = %d\tft = %d\n\n", or, ft);
	return (0);
}

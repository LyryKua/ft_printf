#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	setlocale(LC_ALL, "");
	int or = -1, ft = -1;

//	or =    printf("   printf:\t|%d|\n", 42);
//	ft = ft_printf("ft_printf:\t|%d|\n", 42);
//	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%20ld|\t|%li|\t|%20hhd|\t|%20hd|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	ft = ft_printf("ft_printf:\t|%20ld|\t|%li|\t|%20hhd|\t|%20hd|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	printf("or = %d\tft = %d\n\n", or, ft);

//	or =    printf("   printf:\t|%5hO|\t|%20lO|\n", SHRT_MIN, LONG_MIN);
//	ft = ft_printf("ft_printf:\t|%5hO|\t|%20lO|\n", SHRT_MIN, LONG_MIN);
//	printf("or = %d\tft = %d\n\n", or, ft);

//	or =    printf("   printf:\t|%hhd|\n", 15000);
//	ft = ft_printf("ft_printf:\t|%hhd|\n", 15000);
//	printf("or = %d\tft = %d\n\n", or, ft);
	return (0);
}

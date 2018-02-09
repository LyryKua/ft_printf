#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	or, ft;

	or =    printf("   printf:\t|%d|\n", 42);
	ft = ft_printf("ft_printf:\t|%d|\n", 42);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%.18u|\n", INT_MAX + 1);
	ft = ft_printf("ft_printf:\t|%.18u|\n", INT_MAX + 1);
	printf("or = %d\tft = %d\n\n", or, ft);
	return (0);
}

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
//	int	nbr = 42;
	int	or, ft;

	or =    printf("   printf:\t|%#5x|\n", 0);
	ft = ft_printf("ft_printf:\t|%#5x|\n", 0);
	printf("or = %d\tft = %d\n", or, ft);

	or =    printf("   printf:\t|%#25x|\n", 23);
	ft = ft_printf("ft_printf:\t|%#25x|\n", 23);
	printf("or = %d\tft = %d\n", or, ft);

	ft = ft_printf("ft_printf:\t|%*b|\n", 10, 5);
	printf("or = %d\tft = %d\n", or, ft);
	return (0);
}

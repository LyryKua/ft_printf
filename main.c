#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int	nbr = 42;
	int	or, ft;

	or =    printf("   printf:\t|%*d|\n", 5, nbr);
	ft = ft_printf("ft_printf:\t|%*d|\n", 5, nbr);
	printf("or = %d\tft = %d\n", or, ft);
	return (0);
}

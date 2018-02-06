#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int	nbr = 42;
	int	or, ft;

	or =    printf("   printf:\t|%-#5x|\n", 0);
	ft = ft_printf("ft_printf:\t|%-#5x|\n", 0);
	printf("or = %d\tft = %d\n\n", or, ft);

	return (0);
}

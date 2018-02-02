#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
//	int	nbr = 42;
	int	or, ft;

	or =    printf("   printf:\t|%-#5x|\n", 0);
	ft = ft_printf("ft_printf:\t|%-#5x|\n", 0);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%-#.4x|\n", 0x2a);
	ft = ft_printf("ft_printf:\t|%-#.4x|\n", 0x2a);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%-#5x|\n", 0x1);
	ft = ft_printf("ft_printf:\t|%-#5x|\n", 0x1);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%-5x|\n", 0x1);
	ft = ft_printf("ft_printf:\t|%-5x|\n", 0x1);
	printf("or = %d\tft = %d\n\n", or, ft);

	or =    printf("   printf:\t|%-#.3x|\n", 0x17);
	ft = ft_printf("ft_printf:\t|%-#.3x|\n", 0x17);
	printf("or = %d\tft = %d\n\n", or, ft);

	ft_printf("{red}Hello, World!{normal}\n");

	return (0);
}

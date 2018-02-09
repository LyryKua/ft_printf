#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	n;

	ft_printf("ft_printf:\t%hhd\n", CHAR_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %hhd]\n\n", CHAR_MAX - 1);

	ft_printf("ft_printf:\t%hhd\n", CHAR_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %hhd]\n\n", CHAR_MAX);

	ft_printf("ft_printf:\t%hhd\n", CHAR_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %hhd]\n\n", CHAR_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%hd\n", SHRT_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %hd]\n\n", SHRT_MAX - 1);

	ft_printf("ft_printf:\t%hd\n", SHRT_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %hd]\n\n", SHRT_MAX);

	ft_printf("ft_printf:\t%hd\n", SHRT_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %hd]\n\n", SHRT_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%d\n", INT_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %d]\n\n", INT_MAX - 1);

	ft_printf("ft_printf:\t%d\n", INT_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %d]\n\n", INT_MAX);

	ft_printf("ft_printf:\t%d\n", INT_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %d]\n\n", INT_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%ld\n", LONG_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %ld]\n\n", LONG_MAX - 1);

	ft_printf("ft_printf:\t%ld\n", LONG_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %ld]\n\n", LONG_MAX);

	ft_printf("ft_printf:\t%ld\n", LONG_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %ld]\n\n", LONG_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%lld\n", LONG_LONG_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %lld]\n\n", LONG_LONG_MAX - 1);

	ft_printf("ft_printf:\t%lld\n", LONG_LONG_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %lld]\n\n", LONG_LONG_MAX);

	ft_printf("ft_printf:\t%lld\n", LONG_LONG_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %lld]\n\n", LONG_LONG_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%jd\n", LONG_LONG_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %jd]\n\n", LONG_LONG_MAX - 1);

	ft_printf("ft_printf:\t%jd\n", LONG_LONG_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %jd]\n\n", LONG_LONG_MAX);

	ft_printf("ft_printf:\t%jd\n", LONG_LONG_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %jd]\n\n", LONG_LONG_MAX + 1);

	printf("//***********************************************************\n");

	ft_printf("ft_printf:\t%zd\n", UINT_MAX - 1);
	   printf("   printf:\t[dec_long_long | nbr = %zd]\n\n", UINT_MAX - 1);

	ft_printf("ft_printf:\t%zd\n", UINT_MAX);
	   printf("   printf:\t[dec_long_long | nbr = %zd]\n\n", UINT_MAX);

	ft_printf("ft_printf:\t%zd\n", UINT_MAX + 1);
	   printf("   printf:\t[dec_long_long | nbr = %zd]\n\n", UINT_MAX + 1);
	return (0);
}

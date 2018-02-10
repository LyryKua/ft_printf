#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"

int main(void)
{
	int or, ft;

	setlocale(LC_ALL, "");
	or =    printf("   printf:\t|%S|\n", L"Пирвіт, Світе!");
	ft = ft_printf("ft_printf:\t|%S|\n", L"Пирвіт, Світе!");
	printf("or = %d\tft = %d\n\n", or, ft);
	return (0);
}
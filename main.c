#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main(void)
{
	ft_printf("Mama {red}mula{normal} ramy\n");
	ft_printf("%- 42d\n", 42);
//	ft_printf("Mama \033[31mmula\033[0m ramy\n");
	return (0);
}

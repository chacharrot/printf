#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c = '1';

	printf("%*c\n", -1, c);
	printf("%-*c\n", -3, c);
	ft_printf("%*c\n", -1, c);
	return 0;
}
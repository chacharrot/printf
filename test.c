#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *c = "aaaaaa";
	printf("%010.9sbb\n", c);
	return 0;
}
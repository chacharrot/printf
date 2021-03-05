#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *c = "aaaaaa";
	char **str;

	str[1] = "123";
	str[2] = "456";
	printf("%010.9sbb\n", c);
	printf("%c", *str[1]);
	return 0;
}
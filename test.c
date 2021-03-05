#include "ft_printf.h"

int main()
{
	char *c = "aaaaaa";
	char **str;

	printf("%-10.9sbb\n", c);
	ft_printf("%-10.9sbb\n", c);
	return 0;
}

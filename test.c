#include "ft_printf.h"

int main()
{
	char *c = "aaaaaa";
	char **str;
	int d = -111;

	printf("%-5d2\n", d);
	printf("%.3d\n", d);
	return 0;
}

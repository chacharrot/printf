#include "ft_printf.h"

int main()
{
	char *c = "aaaaaa";
	char **str;
	size_t d = 111;

	ft_printf("%.20u 2\n", d);
	return 0;
}

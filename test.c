#include "ft_printf.h"

int main()
{
	char *c = "aaaaaa";
	char **str;
	int d = 111;

	printf("%13.8p 2\n", c);
	ft_printf("%13.8p 2\n", c);
	printf("%10p a\n",c);
	ft_printf("%10p a\n", c);
	printf("%.p a\n", c);
	ft_printf("%.p a\n", c);
	printf("%p a\n", c);
	ft_printf("%p a\n", c);
	printf("%3p a\n", c);
	ft_printf("%3p a\n", c);
	printf("%15p a\n", c);
	ft_printf("%15p a\n", c);
	printf("%013.10p a\n", c);
	ft_printf("%013.10p a\n", c);
	return 0;
}


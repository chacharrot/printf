#include "ft_printf.h"

int main()
{
	char *c = "aaaaaa";
	char **str;
	int d = 111;

	printf("%p 2\n", c);
	return 0;
}

//폭 '-' 인식. 정밀도, '0'인식안함.
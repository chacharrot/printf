#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>





int	main()
{
	char *s = "111";
	char *s2 = "222";
	char a = 'a';
	int i;
	i = -111;
	write(1, "1", 1);
	printf("\n%3.3%22\n");
	return 0;
}

// *은 + 0 뒤 .* 앞 
// .* 맨뒤
// + 0 은 맨앞 둘의 순서 상관 없음
#include "ft_printf.h"

void	ft_putwidth(fmtdata data, size_t size)
{
	while(data.width - size > 0)
	{
		if (data.zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		size++;
		data.rev += 1;
	}
}
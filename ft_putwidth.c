#include "ft_printf.h"

void	ft_putwidth(fmtdata *data, size_t size)
{
	size_t	i;

	i = size;
	while(data->width - i > 0)
	{
		if (data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

#include "ft_printf.h"

void	do_c(va_list ap, fmtdata *data)
{
	if (data->minus)
		ft_putchar(va_arg(ap, int), *data);
	if (data->width)
		ft_putwidth(data, 1);
	if (!data->minus)
		ft_putchar(va_arg(ap, int), *data);
	data->rev += 1;
}
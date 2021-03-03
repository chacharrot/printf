#include "ft_printf.h"

int		ft_putchar(char c, fmtdata *data)
{
	write(1, &c, 1);
	data->rev += 1;
	return (1);
}

void	data_set(fmtdata *data)
{
	data->width = 0;
	data->precision = -1;
	data->zero = 0;
	data->minus = 0;
	data->rev = 0;
}

int		ft_f(char format)
{
	if (format == '%')
		return (1);
	if (format == '0')
		return (1);
	if (format == '-')
		return (1);
	if (format == '*')
		return (1);
	
}
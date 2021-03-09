#include "ft_printf.h"

void	ft_putwidth(fmtdata *data, size_t size)
{
	size_t	i;

	i = size;
	while(data->width > i)
	{
		if (data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_d(fmtdata *data, size_t size)
{
	size_t	i;

	i = size;
	if (data->precision > (int)size)
		i = data->precision;
	if (data->int_minus)
		i++;
	while(data->width > i)
	{
		if (data->zero && data->precision == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_p(fmtdata *data)
{
	size_t	i;

	i = 9;
	if (data->precision > 9)
		i = data->precision;
	while(data->width > i + 2)
	{
		if (data->zero && data->precision == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}
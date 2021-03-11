#include "ft_printf.h"

void	ft_putwidth(fmtdata *data, int size)
{
	int	i;

	i = size;
	if (data->pre > i)
		i = data->pre;
	if (data->pre >= 0 && data->pre < i)
		i = data->pre;
	while (data->width > i)
	{
		if (data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_d(fmtdata *data, int size)
{
	int	i;

	i = size;
	if (data->pre > size)
		i = data->pre;
	if (data->int_minus)
		i++;
	while (data->width > i)
	{
		if (data->zero && data->pre == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_p(fmtdata *data)
{
	int	i;

	i = 9;
	if (data->pre > 9)
		i = data->pre;
	while (data->width > i + 2)
	{
		if (data->zero && data->pre == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}
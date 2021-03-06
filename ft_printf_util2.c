#include "ft_printf.h"

void	ft_putstr_d(char *str, fmtdata *data, size_t str_len)
{
	int	i;

	if (data->int_minus)
		ft_putchar('-', data);
	if (data->precision == -1 && data->zero)
		ft_putwidth_d(data, str_len);
	i = data->precision;
	if (data->precision > (int)str_len)
		while (i-- - (int)str_len > 0)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

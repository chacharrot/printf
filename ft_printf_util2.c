#include "ft_printf.h"

void	ft_putstr_d(char *str, fmtdata *data, size_t str_len)
{
	int	i;

	if (data->int_minus)
		ft_putchar('-', data);
	if (data->precision == -1 && data->zero && data->int_minus)
		ft_putwidth_d(data, str_len);
	i = data->precision;
	if (data->precision > (int)str_len)
		while (i-- - (int)str_len > 0)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

void	ft_putstr_p(char *str, fmtdata *data, size_t str_len)
{
	int		i;
	size_t	k;

	k = str_len;
	write(1, "0x", 2);
	data->rev += 2;
	while(9 > k)
		ft_putchar('0', data);
	if (data->precision == -1 && data->zero)
		ft_putwidth_p(data, 11);
	i = data->precision;
	if (data->precision > 9)
		while (i-- > 9)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

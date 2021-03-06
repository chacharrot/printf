#include "ft_printf.h"

void	do_d(va_list ap, fmtdata *data)
{
	int		num;
	char	*number;
	size_t	num_size;

	num = va_arg(ap, int);
	number = ft_itoa(num, data);
	num_size = ft_strlen(number);
	if (data->precision != -1 && data->precision < num_size)
		data->precision = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->precision || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}

#include "ft_printf.h"

void	do_p(va_list ap, fmtdata data)
{
	unsigned long long	num;
	char				*number;
	size_t				num_size;

	num = va_arg(ap, void *);
	number = ft_itoa_p(num, 'x');
	num_size = ft_strlen(number);
	if (data->precision != -1 && data->precision < num_size)
		data->precision = num_size;
	if (data->minus)
		ft_putstr_p(number, data, num_size);
	if (data->width && (data->precision || !data->zero))
		ft_putwidth_p(data, num_size);
	if (!data->minus)
		ft_putstr_p(number, data, num_size);
}

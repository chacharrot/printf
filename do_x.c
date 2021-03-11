#include "ft_printf.h"

void	do_x(va_list ap, fmtdata *data)
{
	size_t	num;
	char	*number;
	int		num_size;

	num = va_arg(ap, unsigned int);
	number = ft_itoa_hex(num, 'x', data);
	num_size = ft_strlen(number);
	if (data->pre != -1 && data->pre < num_size)
		data->pre = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->pre != -1 || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}

void	do_X(va_list ap, fmtdata *data)
{
	size_t	num;
	char	*number;
	int		num_size;

	num = va_arg(ap, unsigned int);
	number = ft_itoa_hex(num, 'X', data);
	num_size = ft_strlen(number);
	if (data->pre != -1 && data->pre < num_size)
		data->pre = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->pre != -1 || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}
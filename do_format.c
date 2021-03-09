#include "ft_printf.h"

void	do_c(va_list ap, fmtdata *data)
{
	if (data->minus)
		ft_putchar(va_arg(ap, int), data);
	if (data->width)
		ft_putwidth(data, 1);
	if (!data->minus)
		ft_putchar(va_arg(ap, int), data);
	data->rev += 1;
}

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
	if (data->width && (data->precision != -1 || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}


void	do_u(va_list ap, fmtdata *data)
{
	size_t	num;
	char	*number;
	size_t	num_size;

	num = va_arg(ap, unsigned int);
	number = ft_itoa_u(num);
	num_size = ft_strlen(number);
	if (data->precision != -1 && data->precision < num_size)
		data->precision = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->precision != -1 || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}

void	do_p(va_list ap, fmtdata *data)
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
	if (data->width && (data->precision != -1 || !data->zero))
		ft_putwidth_p(data, num_size);
	if (!data->minus)
		ft_putstr_p(number, data, num_size);
}

int		do_s(va_list ap, fmtdata *data)
{
	char *str;
	size_t	str_len;

	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (data->precision > str_len)
		data->precision = str_len;
	if(data->minus)
		ft_putstr(str, data, str_len);
	if(data->width)
		ft_putwidth(data, data->precision);
	if(!data->minus)
		ft_putstr(str, data, str_len);
	return (1);
}

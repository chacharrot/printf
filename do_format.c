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
	char	*number;
	int		num_size;
	int		num;

	num = va_arg(ap, int);
	number = ft_itoa(num, data);
	num_size = ft_strlen(number);
	if (data->pre != -1 && data->pre < num_size)
		data->pre = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->pre != -1 || !data->zero || !data->int_minus))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}


void	do_u(va_list ap, fmtdata *data)
{
	size_t	num;
	char	*number;
	int		num_size;

	num = va_arg(ap, unsigned int);
	number = ft_itoa_u(num, data);
	num_size = ft_strlen(number);
	if (data->pre != -1 && data->pre < num_size)
		data->pre = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->pre != -1 || !data->zero || !data->int_minus))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}

void	do_p(va_list ap, fmtdata *data)
{
	unsigned long long	num;
	char				*number;
	int					num_size;

	num = va_arg(ap, unsigned long long);
	number = ft_itoa_p(num, data);
	num_size = ft_strlen(num);
	if (data->pre != -1 && data->pre < num_size)
		data->pre = num_size;
	if (data->minus)
		ft_putstr_p(number, data, num_size);
	if (data->width && (data->pre != -1 || !data->zero || !data->int_minus))
		ft_putwidth_p(data);
	if (!data->minus)
		ft_putstr_p(number, data, num_size);
}

int		do_s(va_list ap, fmtdata *data)
{
	char	*str;
	int		str_len;

	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (data->pre >= 0 && data->pre < str_len)
		str_len = data->pre;
	if (data->pre > str_len)
		data->pre = str_len;
	if(data->minus)
		ft_putstr(str, data, str_len);
	if(data->width)
		ft_putwidth(data, str_len);
	if(!data->minus)
		ft_putstr(str, data, str_len);
	return (1);
}

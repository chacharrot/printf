#include "ft_printf.h"

int		ft_putchar(char c, fmtdata *data)
{
	write(1, &c, 1);
	data->rev += 1;
	return (1);
}

void	ft_putstr(char *str, fmtdata *data, size_t str_len)
{
	if (data->precision < str_len)
		str_len = data->precision;
	if (data->precision > str_len)
		data->precision = str_len;
	write(1, str, str_len);
	data->rev += str_len;
}

void	data_set(fmtdata *data)
{
	data->width = 0;
	data->precision = -1;
	data->zero = 0;
	data->minus = 0;
	data->rev = 0;
	data->int_minus = 0;
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
	if (format >= '0' && format <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
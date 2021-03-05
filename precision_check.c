#include "ft_printf.h"

int		precision_check(char *format, va_list ap, fmtdata *data)
{
	int	i;

	i = 0;
	data->precision = 0;
	if (format[i] == '*' && !data->precision)
	{
		data->precision = va_arg(ap, int);
		return (i);
	}
	if (format[i] >= '0' && format[i] <= '9' && !data->precision)
	{
		while (format[i] >= '0' && format[i] <= '9')
			data->precision = data->precision * 10 + format[i++] - '0';
	}
	printf("%d pre\n", data->precision);
	return (i);
}

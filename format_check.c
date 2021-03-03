#include "ft_printf.h"

int		format_check(char *format, va_list ap, fmtdata *data)
{
	int i;

	i = 1;
	while (format[i] && ft_f(format[i]))
	{
		if (format[i] == '%')
			i += ft_putchar('%', data);
		if (format[i] == '0' && !data.width && !data.minus)
			data->zero = 1;
		if (format[i] == '-')
		{
			data->minus = 1;
			data->zero = 0;
		}
		if (format[i] == '*' && data->precision == -1 && !data.width)
			data->width = va_arg(ap, int);
		if (format[i] >= '0' && format[i] <= '0' && data->precision == -1 && !data.width)
				while (format[i] >= '0' && format[i] <= '0')
					data.width = data.width * 10 + format[i++] - '0';
		if (format[i] == '.')
		{
			i++;
			i += precision_check(&format[i], ap, data) - 1;
		}
		i++;
	}
	return (i);
}
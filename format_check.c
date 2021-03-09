#include "ft_printf.h"

static void 	data_minus(fmtdata *data)
{
	data->minus = 1;
	data->zero = 0;
}

static void		data_width(va_list ap, fmtdata *data)
{
	data->width = va_arg(ap, int);
	if (data->width < 0)
	{
		data->minus = 1;
		data->width *= -1;
	}
}

static int		precision_check(char *format, va_list ap, fmtdata *data)
{
	int	i;

	i = 0;
	data->precision = 0;
	if (*format == '\0')
		return (0);
	if (format[i] == '*')
		data->precision = va_arg(ap, int);
	else if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
			data->precision = data->precision * 10 + format[i++] - '0';
		i--;
	}
	return (i);
}

int			format_check(char *format, va_list ap, fmtdata *data)
{
	int i;

	i = 1;
	while (format[i] && ft_f(format[i]))
	{
		if (format[i] == '%')
			i += ft_putchar('%', data);
		else if (format[i] == '0' && !data->width && !data->minus)
			data->zero = 1;
		else if (format[i] == '-')
			data_minus(data);
		else if (format[i] == '*' && data->precision == -1 && !data->width)
			data_width(ap, data);
		else if (format[i] >= '0' && format[i] <= '9' && data->precision == -1)
		{
			while (format[i] >= '0' && format[i] <= '9')
				data->width = data->width * 10 + format[i++] - '0';
			i--;
		}
		else if (format[i] == '.')
			i += precision_check(&format[i + 1], ap, data);
		i++;
	}
	return (i);
}

void		format_start(char *format, va_list ap, fmtdata *data)
{
	int		i;

	data->rev = 0;
	i = 0;
	while (format[i])
	{
		data_set(data);
		if (format[i] != '%')
			i += ft_putchar(format[i], data);
		else if(format[i] == '%' && format[i + 1])
			{
				i += format_check(&format[i], ap, data);
				i += do_print(&format[i], ap, data);
			}
	}
}

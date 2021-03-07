#include "ft_printf.h"

void	format_start(char *format, va_list ap, fmtdata *data)
{
	int		i;

	data->rev = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			i += ft_putchar(format[i], data);
		else if(format[i] == '%' && format[i + 1])
			{
				i += format_check(&format[i], ap, data, i);
				i += do_print(&format[i], ap, data);
				data_set(data);
			}
	}
}
printf("%d\n", );
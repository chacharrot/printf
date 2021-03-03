#include "ft_printf.h"

void	format_start(char *format, va_list ap, fmtdata *data)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			{
				write(1, &format[i], 1);
				data->rev += 1;
				i++;
			}
		else if(format[i] == '%' && format[i + 1])
			{
				i += format_check(&format[i], ap, data);
				i += do_print(&format[i], ap, data);
			}
	}
}
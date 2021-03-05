#include "ft_printf.h"

int		do_s(va_list ap, fmtdata *data)
{
	char *str;
	size_t	str_len;

	str_len = ft_strlen(str);
	str = va_arg(ap, char *);
	if (data->precision > str_len)
		data->precision = str_len;
	if(data->minus)
		ft_putstr(str, data);
	if(data->width)
		ft_putwidth(data, data->precision);
	if(!data->minus)
		ft_putstr(str, data);
	return (1);
}
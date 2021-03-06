#include "ft_printf.h"

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

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	fmtdata		*data;

	va_start(ap, format);
	format_start(format, ap, data);
	va_end(ap);
	return (data->rev);
}
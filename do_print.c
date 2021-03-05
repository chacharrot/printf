#include "ft_printf.h"

int	do_print(char *format, va_list ap, fmtdata *data)
{
	if (*format == 'c')
		do_c(ap, data);
	if (*format == 's')
		do_s(ap, data);
	return (1);
}

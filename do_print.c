#include "ft_printf.h"

int	do_print(char *format, va_list ap, fmtdata *data)
{
	if (*format == '\0')
		return (0);
	if (*format == '%')
		do_percent(ap, data);
	if (*format == 'c')
		do_c(ap, data);
	if (*format == 's')
		do_s(ap, data);
	if (*format == 'd' || *format == 'i')
		do_d(ap, data);
	if (*format == 'u')
		do_u(ap, data);
	if (*format == 'x')
		do_x(ap, data);
	if (*format == 'X')
		do_X(ap, data);
	if (*format == 'p')
		do_p(ap, data);
	return (1);
}

#include <unistd.h>
#include <stdarg.h>

void	no_minus_do_c(va_list ap, pf_data data)
{
	char	c;
	size_t	widthc;

	widthc = data->width;
	c = va_arg(ap, int);
	data->apr = ap;
	if (data->width)
		data->rev += (data->width - 1);
	if (data->zero)
		while ((widthc - 1) > 0)
		{
			write(1, "0", 1);
			widthc--;
		}
	else
		while ((widthc - 1) > 0)
		{
			write(1, " ", 1);
			widthc--;
		}
	write(1, &c , 1);
	data->rev += 1;
	data->i += 1;
}

void	minus_do_c(va_list ap, pf_data data)
{
	char	c;
	size_t	widthc;

	widthc = data->width;
	c = va_arg(ap, int);
	data->apr = ap;
	write(1, &c, 1);
	data->width += 1;
	if (data->width)
	{
		data->rev += (data->width - 1);
		while (widthc - 1 > 0)
		{
				write(1, " ", 1);
				widthc--;
		}
	}
}
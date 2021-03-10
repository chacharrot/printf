
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	fmtdata_s
{
	int		width;
	int		precision;
	int		zero;
	int		minus;
	int		rev;
	int		int_minus;
}				fmtdata;

static void	data_set(fmtdata *data)
{
	data->width = 0;
	data->precision = -1;
	data->zero = 0;
	data->minus = 0;
	data->int_minus = 0;
}

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

static int			format_check(char *format, va_list ap, fmtdata *data)
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

static	void		format_start(char *format, va_list ap, fmtdata *data)
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


static int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	do_print(char *format, va_list ap, fmtdata *data)
{
	int num;

	if (*format == 'd' || *format == 'i')
	{
		num = va_arg(ap, int);
		do_d(num, data);
	}
	return (1);
}

static void	ft_putwidth_d(fmtdata *data, int size)
{
	int	i;

	i = size;
	if (data->precision > size)
		i = data->precision;
	if (data->int_minus)
		i++;
	while (data->width > i)
	{
		if (data->zero && data->precision == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}


static void	ft_putstr_d(char *str, fmtdata *data, int str_len)
{
	int	i;

	if (data->int_minus)
		ft_putchar('-', data);
	if (data->precision == -1 && data->zero && data->int_minus)
		ft_putwidth_d(data, str_len);
	i = data->precision;
	if (data->precision > (int)str_len)
		while (i-- - (int)str_len > 0)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

static void	do_d(int num, fmtdata *data)
{
	char	*number;
	int		num_size;

	number = ft_itoa(num, data);
	num_size = ft_strlen(number);
	if (data->precision != -1 && data->precision < num_size)
		data->precision = num_size;
	if (data->minus)
		ft_putstr_d(number, data, num_size);
	if (data->width && (data->precision != -1 || !data->zero))
		ft_putwidth_d(data, num_size);
	if (!data->minus)
		ft_putstr_d(number, data, num_size);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	fmtdata		*data;

	data_set(data);
	va_start(ap, format);
	format_start(format, ap, data);
	va_end(ap);
	return (data->rev);
}

int main()
{
	int i = 111;
	printf("%.*d\n", -1, i);
	ft_printf("%.*d\n", -1, i);
	return 0;
}
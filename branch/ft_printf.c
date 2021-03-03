
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct pf_data
{
	int			minus;
	int			zero;
	size_t		width;
	long long	rev;
	size_t		i;
	size_t		presicion;
}	pf_data;

size_t ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int     digitnumber(int n)
{
    int i;

    i = 0;
    if(n < 0)
        i = 1;
    while(n)
    {    
        n = n/10;
        i++;
    }
    return(i);
}

char    *ft_itoa(int n)
{
    char    *str;
    int     i;

    i = digitnumber(n);
    str = (char *)malloc(sizeof(char) * (i + 1));
    if(!str)
        return(NULL);
    if(n < 0)
    {
        n = n * -1;
        *str = 45;
        i++;
    }
    str[i] ='\0';
    while(i)
    {
        str[--i] = n % 10 + '0';
        n = n/10;
    }
    return(str);
}

void	data_zero(pf_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->width = 0;
	data->rev = 0;
	data->i = 0;
	data->presicion = 0;
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	pf_data	*data;

	va_start(ap, format);
	data_zero(data);
	while (format[data->i])
	{
		data_zero(data);
		printf("1\n");
		if (format[data->i] != '%')
		{
			write(1, &format[data->i], 1);
			data->rev += 1;
			data->i += 1;
		}
		else
			check_mwp(&format[data->i], ap, data);
		if (check_seosik(&format[data->i]))
			do_print(ap, data, &format[data->i]);
	}
	return (data->rev);
}

void	check_mwp(const char *str, va_list ap, pf_data *data)
{
	str++;
	data->i += 1;
	while (*str && check_flag(*str))
	{
		if (*str == '%')
		{
			write(1, "%", 1);
			data->rev += 1;
			data->i += 1;
			return;
		}
		if ((*str == '0' || *str == '-') && !data->width && !data->presicion)
		{
			while (*str == '0' || *str == '-')
			{
				minus_zero(str, data);
				str++;
				data->i += 1;
			}
		}
		if (*str == '*')
			data->width = va_arg(ap, size_t);
		if (*str == '.')
		{
			str = dot_here(str, ap, data);
		}
		str++;
		data->i += 1;
	}
}

void	minus_zero(const char *str, pf_data *data)
{
	if (*str == '-')
	{
		data->minus = 1;
		data->zero = 0;
	}
	if (*str == '0' && data->minus == 0)
		data->zero = 1;
}

int		check_flag(const char *str)
{
	if (*str == '0' || *str == '-' || *str == '*' || *str == '.')
		return (1);
	return (0);
}

int		check_seosik(const char *str)
{
	if (*str == 'd' || *str == 'c' || *str == 's')
		return (1);
	return 0;
}

void dot_here(char *str, va_list ap, pf_data *data)
{
    size_t  pre;

    str++;
    data->i += 1;
    if (*str == '*')
    {
        data->presicion = va_arg(ap, size_t);
        return;
    }
    else if (*str <= '9' && *str >= '0' && *str)
    {
        pre = 0;
        while (*str <= '9' && *str >= '0' && *str)
        {
            pre = pre * 10 + (*str - '0');
            data->presicion = pre;
        }
    }
    return;
}

void	do_print(va_list ap, pf_data *data, char *s)
{
	if (*s == 'd')
		do_d(ap,data);
}

void	do_d(va_list ap, pf_data *data)
{
	if (!data->zero && !data->presicion && !data->minus)
		width_do_d(ap, data);
	if (data->minus == 1)
		minus_do_d(ap, data);
	else if (data->presicion)
		no_minus_presicion_do_d(ap, data);
	else if (data->zero == 1 && data->presicion == 0)
		zero_do_d(ap, data);
}

void	no_minus_presicion_do_d(va_list ap, pf_data *data)
{
	int		number;
	char	*num;
	size_t	num_len;
	size_t	width_wt;

	number = va_arg(ap, int);
	num = ft_itoa(number);
	num_len = ft_strlen(num);
	if (num_len >= data->presicion)
		width_wt = num_len;
	else if (num_len < data->presicion)
		width_wt = data->presicion;
	if (data->width)
	{
		while (data->width - width_wt > 0)
		{
			write(1, " ", 1);
			data->rev += 1;
			data->width--;
		}
	}
	if (number < 0)
	{
		write(1, "-", 1);
		num++;
		num_len--;
	}
	if (data->presicion)
	{
		while(data->presicion - num_len > 0)
		{
			write(1, "0", 1);
			data->rev += 1;
			data->presicion -= 1;
		}
	}
	write(1, num, num_len);
	data->rev += num_len;
}

void	minus_do_d(va_list ap, pf_data *data)
{
	int		number;
	char	*num;
	size_t	num_len;
	size_t	width_wt;

	number = va_arg(ap, int);
	num = ft_itoa(number);
	num_len = ft_strlen(num);
	if (number < 0)
	{
		write(1, "-", 1);
		data->rev += 1;
		num++;
		num_len--;
	}
	while (data->presicion - num_len > 0)
	{
		write(1, "0", 1);
		data->rev += 1;
		data->presicion--;
	}
	write(1, num, num_len);
	data->rev += num_len;
	while (data->width - num_len > 0)
	{
		write(1, " ", 1);
		data->rev += 1;
	}
}

void	zero_do_d(va_list ap, pf_data *data)
{
	int		number;
	char	*num;
	size_t	num_len;
	size_t	width_wt;

	number = va_arg(ap, int);
	num = ft_itoa(number);
	num_len = ft_strlen(num);
	if (number < 0)
	{
		write(1, "-", 1);
		data->rev += 1;
		num++;
		num_len--;
	}
	while (data->width - num_len > 0)
	{
		write(1, "0", 1);
		data->rev += 1;
		data->presicion--;
	}
	write(1, num, num_len);
	data->rev += num_len;
}

void	width_do_d(va_list ap, pf_data *data)
{
	int		number;
	char	*num;
	size_t	num_len;
	size_t	width_wt;

	number = va_arg(ap, int);
	num = ft_itoa(number);
	num_len = ft_strlen(num);
	while (data->width - num_len > 0)
	{
		write(1, " ", 1);
		data->rev += 1;
		data->width--;
	}
		if (number < 0)
	{
		write(1, "-", 1);
		data->rev += 1;
		num++;
		num_len--;
	}
	write(1, num, num_len);
	data->rev += num_len;
}

int main (void)
{
	int d;

	d = 111;
	printf("1%4.4d\n", d);
	ft_printf("1%4.4d\n", d);
	return 0;
}
#include <unistd.h>
#include <stdarg.h>

void	no_minus_do_s(va_list ap, pf_data data)
{
	char	*s;
	size_t	s_len;

	s = va_arg(ap, char *);
	data->apr = ap;
	s_len = ft_strlen(s);
	if (data->width && data->width > s_len)
	{
		if(data->presicion && data->presicion < s_len)
			s_len = data->presicion;
		while (data->width - s_len > 0)
			{
				if(data->zero)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				data->width -= 1;
				data->rev += 1;
			}
	}
	write(1, s, s_len);
	data->rev += s_len;
	data->i += 1;
}

void	minus_do_s(va_list ap, pf_data data)
{
	char	*s;
	size_t	s_len;

	s = va_arg(ap, char *);
	data->apr = ap;
	s_len = ft_strlen(s);
	if (data->presicion && data->presicion < s_len)
			s_len = data->presicion;
	write(1, s, s_len);
	data->rev += s_len;
	if (data->width && data->width > s_len)
	{
		while (data->width - s_len > 0)
		{
			write(1, " ", 1);
			data->width -= 1;
			data->rev += 1;
		}
	}
	data->i += 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:33:54 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:37:19 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		data_minus(fmtdata *data)
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
		data->zero = 0;
	}
}

static int		pre_check(char *format, va_list ap, fmtdata *data)
{
	int	i;

	i = 0;
	data->pre = 0;
	if (*format == '\0')
		return (0);
	if (format[i + 1] == '*')
	{
		data->pre = va_arg(ap, int);
		if (data->pre < 0)
			data->pre = -1;
		i++;
		return (i);
	}
	else if (format[i + 1] >= '0' && format[i + 1] <= '9')
	{
		while (format[i + 1] >= '0' && format[i + 1] <= '9')
		{
			data->pre = data->pre * 10 + format[i + 1] - '0';
			i++;
		}
	}
	return (i);
}

int				format_check(char *format, va_list ap, fmtdata *data)
{
	int i;

	i = 1;
	while (format[i] && ft_f(format[i]))
	{
		if (format[i] == '0' && !data->width && !data->minus)
			data->zero = 1;
		else if (format[i] == '-')
			data_minus(data);
		else if (format[i] == '*' && !data->width)
			data_width(ap, data);
		else if (format[i] >= '1' && format[i] <= '9' && data->pre == -1)
		{
			while (format[i] >= '0' && format[i] <= '9')
				data->width = data->width * 10 + format[i++] - '0';
			i--;
		}
		else if (format[i] == '.')
			i += pre_check(&format[i], ap, data);
		i++;
	}
	return (i);
}

void			format_start(char *format, va_list ap, fmtdata *data)
{
	int		i;

	data->rev = 0;
	i = 0;
	while (format[i])
	{
		data_set(data);
		if (format[i] != '%')
			i += ft_putchar(format[i], data);
		else if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			i += format_check(&format[i], ap, data);
			i += do_print(&format[i], ap, data);
		}
	}
}

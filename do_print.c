/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:28:36 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:31:41 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_print(char *format, va_list ap, t_fmtdata *data)
{
	if (*format == '\0')
		return (0);
	if (*format == '%')
		do_percent(data);
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
		do_bigx(ap, data);
	if (*format == 'p')
		do_p(ap, data);
	return (1);
}

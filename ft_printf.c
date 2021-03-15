/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:31:58 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:31:59 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	fmtdata		*data;

	data = malloc(sizeof(fmtdata) * 1);
	data_set(data);
	va_start(ap, format);
	format_start(format, ap, data);
	va_end(ap);
	return (data->rev);
}

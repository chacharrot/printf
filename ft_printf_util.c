/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:08:02 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:26:38 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c, t_fmtdata *data)
{
	write(1, &c, 1);
	data->rev += 1;
	return (1);
}

void	data_set(t_fmtdata *data)
{
	data->width = 0;
	data->pre = -1;
	data->zero = 0;
	data->minus = 0;
	data->int_minus = 0;
}

int		ft_f(char format)
{
	if (format == '0')
		return (1);
	if (format == '-')
		return (1);
	if (format == '*')
		return (1);
	if (format >= '0' && format <= '9')
		return (1);
	if (format == '.')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

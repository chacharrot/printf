/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:32:11 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:33:45 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(t_fmtdata *data, int size)
{
	int	i;

	i = size;
	if (data->pre > i)
		i = data->pre;
	if (data->pre >= 0 && data->pre < i)
		i = data->pre;
	while (data->width > i)
	{
		if (data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_d(t_fmtdata *data, int size)
{
	int	i;

	i = size;
	if (data->pre > size)
		i = data->pre;
	if (data->int_minus)
		i++;
	while (data->width > i)
	{
		if (data->zero && data->pre == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_p(t_fmtdata *data, int str_len)
{
	int	i;

	i = str_len;
	if (data->pre > str_len)
		i = data->pre;
	while (data->width > i + 2)
	{
		if (data->zero && data->pre == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
		data->rev += 1;
	}
}

void	ft_putwidth_cper(t_fmtdata *data, int size)
{
	while (data->width > size)
	{
		if (data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		size++;
		data->rev += 1;
	}
}

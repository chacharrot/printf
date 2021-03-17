/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:29:12 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:30:04 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_d(char *str, t_fmtdata *data, int str_len)
{
	int	i;

	if (data->int_minus)
		ft_putchar('-', data);
	if (data->pre == -1 && data->zero && data->int_minus)
		ft_putwidth_d(data, str_len);
	i = data->pre;
	if (data->pre > str_len)
		while (i-- - str_len > 0)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
	free(str);
}

void	ft_putstr_p(char *str, t_fmtdata *data, int str_len)
{
	int		i;

	write(1, "0x", 2);
	data->rev += 2;
	if (data->pre == -1 && data->zero)
		ft_putwidth_p(data, str_len);
	i = data->pre;
	if (data->pre > str_len)
		while (i-- > str_len)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
	free(str);
}

void	ft_putstr(char *str, t_fmtdata *data, int str_len)
{
	if (str == NULL)
		return ;
	if (data->pre >= 0 && data->pre < str_len)
		str_len = data->pre;
	if (data->pre > str_len)
		data->pre = str_len;
	write(1, str, str_len);
	data->rev += str_len;
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:59:39 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 21:59:40 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digitnumber(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		digitnumber_u(size_t n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		digitnumber_hex(size_t n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		digitnumber_p(unsigned long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
